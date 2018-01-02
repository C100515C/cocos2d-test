#include "MMNormalWin.h"

MMNormalWin::MMNormalWin() {
	m_sprite = NULL;
}

MMNormalWin::~MMNormalWin() {

}

bool MMNormalWin::init() {
	MMBase::init();
	return true;
}

void MMNormalWin::setBG( const char* sPath ) {
	if(m_sprite != NULL) {
		this->removeChild(m_sprite);
	}
	m_sprite = Sprite::create(sPath);
	this->addChild(m_sprite);

    Size size = m_sprite->getContentSize();
    m_sprite->setPosition(Point(size.width * 0.5f, size.height * 0.5f));
    this->setContentSize(size);
}

void MMNormalWin::setAnchorPoint( const Point& anchorPoint ) {
	Node::setAnchorPoint(anchorPoint);

	/* child的描点也要设置 */
	m_sprite->setAnchorPoint(anchorPoint);
}
