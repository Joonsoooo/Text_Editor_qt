#include "tab_mgr.h"
#include "text_model.h"
#include "q_menus.h"

#include <iostream>
#include <QTabbar>
#include <QTextEdit>


void tab_mgr::create_tab_info(text_model* model)
{
    tab_info* new_tab = new tab_info();

	QTextEdit* text_ed = new QTextEdit();

    new_tab->model = model;
    new_tab->text_ed = text_ed;

    if (m_tab_list.empty())
    {
        m_tab_wid->tabBar()->setContextMenuPolicy(Qt::CustomContextMenu);

        connect(m_tab_wid, SIGNAL(currentChanged(int)), this, SLOT(change_tab(int)));
        connect(m_tab_wid->tabBar(), &QTabBar::customContextMenuRequested, this, &tab_mgr::right_click_tab);

    }
    
    QString tab_name = "탭" + QString::number(m_tab_list.size() + 1);

    m_tab_wid->addTab(text_ed, tab_name);

    m_tab_list.push_back(new_tab);
}

void tab_mgr::right_click_tab(const QPoint& pos)
{
    int tabIndex = m_tab_wid->tabBar()->tabAt(pos);

    if (tabIndex != -1) 
    {
        std::cout << "Right clicked tab index: " << tabIndex << std::endl;
        
		q_menus* tab_menu = new q_menus(m_tab_wid, MENU_TYPE::TAB);

    }
}

void tab_mgr::change_tab(int index)
{
    cout << "tab change: " << index << endl;
}