#ifndef BLUENOISE_H
#define BLUENOISE_H

#include "nutil.h"
#include "vec.h"

template<unsigned int N, class T>
void sample_annulus(T radius, const Vec<N,T> &centre, unsigned int &seed, Vec<N,T> &x)
{
    Vec<N,T> r;
    for(;;){
        for(unsigned int i=0; i<N; ++i){
            r[i]=4*(randhash(seed++)/(T)UINT_MAX-(T)0.5);
        }
        T r2=mag2(r);
        if(r2>1 && r2<=4)
            break;
    }
    x=centre+radius*r;
}

template<unsigned int N, class T>
unsigned long int n_dimensional_array_index(const Vec<N,unsigned int> &dimensions, const Vec<N,T> &x)
{
    unsigned long int k=0;
    if(x[N-1]>=0){
        k=(unsigned long int)x[N-1];
        if(k>=dimensions[N-1]) k=dimensions[N-1]-1;
    }
    for(unsigned int i=N-1; i>0; --i){
        k*=dimensions[i-1];
        if(x[i-1]>=0){
            unsigned int j=(int)x[i-1];
            if(j>=dimensions[i-1]) j=dimensions[i-1]-1;
            k+=j;
        }
    }
    return k;
}

template<unsigned int N, class T>
void bluenoise_sample(T radius, Vec<N,T> xmin, Vec<N,T> xmax, std::vector<Vec<N,T> > &sample,
                      unsigned int seed=0, int max_sample_attempts=30)
{
    sample.clear();
    std::vector<unsigned int> active_list;

    // acceleration grid
    T grid_dx=T(0.999)*radius/std::sqrt((T)N); // a grid cell this size can have at most one sample in it
    Vec<N,unsigned int> dimensions;
    unsigned long int total_array_size=1;
    for(unsigned int i=0; i<N; ++i){
        dimensions[i]=(unsigned int)std::ceil((xmax[i]-xmin[i])/grid_dx);
        total_array_size*=dimensions[i];
    }
    std::vector<int> accel(total_array_size, -1); // -1 indicates no sample there; otherwise index of sample point

    // first sample
    Vec<N,T> x;
    for(unsigned int i=0; i<N; ++i){
        x[i]=(xmax[i]-xmin[i])*(randhash(seed++)/(T)UINT_MAX) + xmin[i];
    }
    sample.push_back(x);
    active_list.push_back(0);
    unsigned int k=n_dimensional_array_index(dimensions, (x-xmin)/grid_dx);
    accel[k]=0;

    while(!active_list.empty()){
        unsigned int r=int(randhashf(seed++, 0, active_list.size()-0.0001f));
        int p=active_list[r];
        bool found_sample=false;
        Vec<N,unsigned int> j, jmin, jmax;
        for(int attempt=0; attempt<max_sample_attempts; ++attempt){
            sample_annulus(radius, sample[p], seed, x);
            // check this sample is within bounds
            for(unsigned int i=0; i<N; ++i){
                if(x[i]<xmin[i] || x[i]>xmax[i])
                    goto reject_sample;
            }
            // test proximity to nearby samples
            for(unsigned int i=0; i<N; ++i){
                int thismin=(int)((x[i]-radius-xmin[i])/grid_dx);
                if(thismin<0) thismin=0;
                else if(thismin>=(int)dimensions[i]) thismin=dimensions[i]-1;
                jmin[i]=(unsigned int)thismin;
                int thismax=(int)((x[i]+radius-xmin[i])/grid_dx);
                if(thismax<0) thismax=0;
                else if(thismax>=(int)dimensions[i]) thismax=dimensions[i]-1;
                jmax[i]=(unsigned int)thismax;
            }
            for(j=jmin;;){
                // check if there's a sample at j that's too close to x
                k=n_dimensional_array_index(dimensions, j);
                if(accel[k]>=0 && accel[k]!=p){ // if there is a sample point different from p
                    if(dist2(x, sample[accel[k]])<sqr(radius))
                        goto reject_sample;
                }
                // move on to next j
                for(unsigned int i=0; i<N; ++i){
                    ++j[i];
                    if(j[i]<=jmax[i]){
                        break;
                    }else{
                        if(i==N-1) goto done_j_loop;
                        else j[i]=jmin[i]; // and try incrementing the next dimension along
                    }
                }
            }
        done_j_loop:
            // if we made it here, we're good!
            found_sample=true;
            break;
            // if we goto here, x is too close to an existing sample
        reject_sample:
            ; // nothing to do except go to the next iteration in this loop
        }
        if(found_sample){
            size_t q=sample.size(); // the index of the new sample
            sample.push_back(x);
            active_list.push_back(q);
            k=n_dimensional_array_index(dimensions, (x-xmin)/grid_dx);
            accel[k]=(int)q;
        }else{
            // since we couldn't find a sample on p's disk, we remove p from the active list
            erase_unordered(active_list, r);
        }
    }
}

#endif
