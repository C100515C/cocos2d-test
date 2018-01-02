#include "MMLabel.h"
#include <string>

MMLabel::MMLabel() {
	m_label = NULL;
}

MMLabel::~MMLabel() {

}

bool MMLabel::init() {
    MMBase::init();

    m_label = Label::create("", "Arial", 24);
    this->addChild(m_label);

	return true;
}

void MMLabel::setsText( const char* sText ) {
	
	m_label->setString(sText);
}

void MMLabel::setsText( int iValue ) {
	setsText(StringUtils::toString(iValue).c_str());
}
void MMLabel::setiFontSize( int iFontSize ) {
    m_label->setSystemFontSize(iFontSize);
}

void MMLabel::setAnchorPoint( const Point& anchorPoint ) {
	Node::setAnchorPoint(anchorPoint);
	m_label->setAnchorPoint(anchorPoint);
}

void MMLabel::setColorRGB( int r, int g, int b ) {
	m_label->setColor(Color3B(r, g, b));
}