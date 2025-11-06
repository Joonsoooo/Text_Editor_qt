#include "q_menus.h"
#include "tab_mgr.h"
#include "save_load_handler.h"

q_menus::q_menus(tab_info* tab, MENU_TYPE type, QWidget* parent)
{
	create_menu(tab, type);
}

q_menus::~q_menus()
{
	delete m_menu;
	delete m_tab_info;
}

void q_menus::create_menu(tab_info* tab, MENU_TYPE type)
{
	if (nullptr == m_menu)
	{
		m_menu = new QMenu();
	}

	switch (type)
	{
	case TAB:
		m_tab_info = tab;

		QAction* saveAction = new QAction("저장", m_menu);
		connect(saveAction, &QAction::triggered, this, &q_menus::save_action);
		m_menu->addAction(saveAction);

		QAction* closeAction = new QAction("닫기", m_menu);
		//connect(closeAction, &QAction::triggered, this, &tab_mgr::onClose);
		m_menu->addAction(closeAction);
		break;
	}

	QPoint globalPos = QCursor::pos();
	m_menu->exec(globalPos);
}

void q_menus::create_menu(MENU_TYPE type)
{
	if (nullptr == m_menu)
	{
		m_menu = new QMenu();
	}

	switch (type)
	{
	case TAB:
		QAction* saveAction = new QAction("저장", m_menu);
		connect(saveAction, &QAction::triggered, this, &q_menus::save_action);
		m_menu->addAction(saveAction);

		QAction* closeAction = new QAction("닫기", m_menu);
		//connect(closeAction, &QAction::triggered, this, &tab_mgr::onClose);
		m_menu->addAction(closeAction);
		break;
	}

	QPoint globalPos = QCursor::pos();
	m_menu->exec(globalPos);
}

void q_menus::save_action()
{
	if (nullptr == m_tab_info)
	{
		cout << "q_menus::save_action - m_tab_info is nullptr" << endl;

		return;
	}
	save_load_handler* save_hndl = new save_load_handler();

	save_hndl->save(m_tab_info->model);
}