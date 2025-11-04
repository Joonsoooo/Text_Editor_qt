#pragma once
#include <iostream>
#include <vector>
#include <QObject>
#include <QTabwidget>

class text_model;
class QTextEdit;

using namespace std;

struct tab_info
{
	text_model* model;
	QTextEdit* text_ed;
};

class tab_mgr : public QObject
{
	Q_OBJECT

public:
	tab_mgr(QObject* parent)
		: QObject(parent), m_tab_wid(nullptr), m_selected(0) 
	{ 
		m_tab_wid = new QTabWidget();

		cout << parent->objectName().toStdString() << endl;
	}

	~tab_mgr() {}

public:
	void create_tab_info(text_model* model);

	QTabWidget* get_tab_widget() const { return m_tab_wid; }
	vector<tab_info*> get_tab_list() const { return m_tab_list; }

private slots:
	void change_tab(int index);
	void right_click_tab(const QPoint& pos);

private:
	vector<tab_info*> m_tab_list;
	QTabWidget* m_tab_wid;

	int m_selected;
};