#pragma once

class oiObject;

class oiContext
{
public:
    explicit oiContext(int uid=-1);
    ~oiContext();

    bool load(const char *path);
    const std::string& getPath() const;

    oiObject* getObject() const;
    int getUid() const;

private:
    int m_uid = 0;

    void reset();

    std::string m_path;
    openvdb::io::Archive* m_archive;
};

class oiContextManager
{
public:
    static oiContext* getContext(int uid);
    static void destroyContext(int uid);

private:
    ~oiContextManager();

    using ContextPtr = std::unique_ptr<oiContext>;
    std::map<int, ContextPtr> m_contexts;
    static oiContextManager s_instance;
};