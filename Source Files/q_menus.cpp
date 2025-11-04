#include "q_menus.h"
#include "tab_mgr.h"
#include "save_load_handler.h"

template<typename T>
void q_menus<T>::create_menu(MENU_TYPE type, T* data)
{
	if (nullptr == m_menu)
	{
		m_menu = new QMenu();
	}

	switch (type)
	{
	case TAB:
		m_curr_data = data;

		QAction* saveAction = new QAction("저장", m_menu);
		connect(saveAction, &QAction::triggered, this, );
		m_menu->addAction(saveAction);

		QAction* closeAction = new QAction("닫기", m_menu);
		connect(closeAction, &QAction::triggered, this, &tab_mgr::onClose);
		m_menu->addAction(closeAction);
		break;
	}

	QPoint globalPos = QCursor::pos();
	m_menu->exec(globalPos);
}

template<typename T>
void q_menus<T>::save()
{
	tab_mgr* tab = (tab_mgr*)m_curr_data;

	tab->get_tab_list();
}
