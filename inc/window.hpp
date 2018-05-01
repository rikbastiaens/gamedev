class Window {
public:
  Window();
  Window(const std::string &title, const sf::Vector2u &size);
  ~Window();

  void BeginDraw();
  void EndDraw();
  
  void Update();

  bool IsDone();
  bool isFullscreen();
  sf::Vector2u GetWindowSize();

  void ToggleFullscreen();

  void Draw(sf::Drawable &drawable);
private:
  void Setup(const std::string &title, const sf::Vector2u &size);
  void Destroy();
  void Create();

  sf::RenderWindow window;
  sf::Vector2u windowSize;
  std::string windowTitle;
  bool isDone;
  bool isFullscreen;
};
