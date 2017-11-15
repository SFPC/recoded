# ofxSvgLoader
Addon for OpenFrameworks for parsing svg files.
Uses Libsvgtiny for parsing paths.

Current version compatible with OpenFrameworks 09.<br/>
OF 0.7->0.8.4: https://github.com/NickHardeman/ofxSvgLoader/releases/tag/1.0

Loads a svg file and parses it for easy navigation.<br/>
<strong>Groups, rectangles, images, circles, ellipses, text and paths/lines.</strong>

Several use cases are shown in the provided example.

Grab a group by passing in the name of the group. <br/>
shared_ptr<ofxSvgGroup> logoGroup = svg.get< ofxSvgGroup>("logo");

Grab nested groups by passing in the hierarchy to the group separated by colons. <br/>
shared_ptr<ofxSvgGroup> cloudGroup = svg.get< ofxSvgGroup>("sky:clouds");

Get all of the elements of a certain type by calling getElementsForType <br/>
vector< shared_ptr<ofxSvgImage> > trees = svg.getElementsForType< ofxSvgImage >("trees");

