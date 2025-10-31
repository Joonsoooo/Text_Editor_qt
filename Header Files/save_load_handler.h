#pragma once
#include <QString>

using namespace std;

class text_model;

class save_load_handler
{

public:
	void save(text_model* model);

	text_model* load(QString file_path);
};
