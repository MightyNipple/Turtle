class Window
{
    void* handle_;
public:
    Window();
    ~Window();
    int Init(int x, int y, int w, int h, const char* title);
    int Show();
};
