#include "save_load_handler.h"
#include "pch.h"
#include "text_model.h"

#include <filesystem>
#include <QFile>
#include <QTextStream>

void save_load_handler::save(text_model* model)
{

}

text_model* save_load_handler::load(QString file_path)
{
    filesystem::path p(file_path.toLocal8Bit().constData());

    string filename = p.filename().string();
    string directory = p.parent_path().string();

    QFile file(file_path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        return nullptr;
    }

    QTextStream in(&file);

    QString text = in.readAll();

    file.close();

    text_model* model = new text_model(text, directory, filename);

    return model;
}