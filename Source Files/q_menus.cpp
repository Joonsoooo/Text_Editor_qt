#include "q_menus.h"

void q_menus::create_menu(MENU_TYPE type)
{
	if (nullptr == m_menu)
	{
		m_menu = new QMenu();
	}

	switch (type)
	{
	case TAB:
		m_menu->addAction("저장");
		m_menu->addAction("닫기");
		break;
	}

	QPoint globalPos = QCursor::pos();
	m_menu->exec(globalPos);
}
