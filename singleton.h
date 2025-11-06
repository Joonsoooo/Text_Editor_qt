#pragma once
template <typename T>
class singleton
{
public:
    static T* create()
    {
        if (!m_instance)
        {
            m_instance = new T();
        }
        return m_instance;
    }

    static T& get()
    {
        if (!m_instance)
        {
            create();
        }
        return *m_instance;
    }

    static void release()
    {
        delete m_instance;
        m_instance = nullptr;
    }

    singleton() {}      
    ~singleton() {}     
    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;

private:
    static T* m_instance;
};

template <typename T>
T* singleton<T>::m_instance = nullptr;
