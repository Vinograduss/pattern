#pragma once

#include <iostream>
#include <stack>

// Этот паттерн предполагает, что у вас есть несколько семейств
// продуктов, находящихся в отдельных иерархиях классов
// (Button/Checkbox). Продукты одного семейства должны иметь
// общий интерфейс.
struct Button {
  virtual void paint() = 0;
  virtual ~Button() {};
};

struct CheckBox {
  virtual void paint() = 0;
  virtual ~CheckBox() {};
};

struct GUIFactory {
  virtual Button *createButton() = 0;
  virtual CheckBox *createCheckBox() = 0;
  virtual ~GUIFactory() {};
};


//////////////////////////////////////////////////

// Семейства продуктов имеют те же вариации (macOS/Windows).
struct WinButton : public Button {
  void paint() override { std::cout << "WinButton\n"; };
};

// Семейства продуктов имеют те же вариации (macOS/Windows).
struct WinCheckBox : public CheckBox {
  void paint() override { std::cout << "WinCheckBox\n"; };
};

// Каждая конкретная фабрика знает и создаёт только продукты
// своей вариации.
struct WinGUIFactory : public GUIFactory {
  Button *createButton() { return new WinButton(); };

  CheckBox *createCheckBox() { return new WinCheckBox(); };
};



//////////////////////////////////////////////////

// Семейства продуктов имеют те же вариации (macOS/Windows).
struct MacButton : public Button {
  void paint() override { std::cout << "MacButton\n"; };
};

// Семейства продуктов имеют те же вариации (macOS/Windows).
struct MacCheckBox : public CheckBox {
  void paint() override { std::cout << "MacCheckBox\n"; };
};


// Несмотря на то, что фабрики оперируют конкретными классами,
// их методы возвращают абстрактные типы продуктов. Благодаря
// этому фабрики можно взаимозаменять, не изменяя клиентский
// код.
struct MacGUIFactory : public GUIFactory {
  Button *createButton() { return new MacButton(); };
  CheckBox *createCheckBox() { return new MacCheckBox(); };
};