#include <iostream>

class Button {
public:
    virtual void paint() = 0;

    virtual ~Button() = default;
};

class WinButton : public Button {
public:
    void paint() override {}
};

class MacButton : public Button {
public:
    void paint() override {}
};


class CheckBox {
public:
    virtual void paint() = 0;

    virtual ~CheckBox() = default;
};

class WinCheckBox : public CheckBox {
public:
    void paint() override {}
};

class MacCheckBox : public CheckBox {
public:
    void paint() override {}
};


class GUIFactory {
public:
    virtual Button *createButton() = 0;

    virtual CheckBox *createCheckBox() = 0;

    virtual ~GUIFactory() = default;
};

class WinFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new WinButton();
    }

    CheckBox *createCheckBox() override {
        return new WinCheckBox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button *createButton() override {
        return new MacButton();
    }

    CheckBox *createCheckBox() override {
        return new MacCheckBox();
    }
};

class Application {
    GUIFactory *factory;
    Button *button = nullptr;
public:
    explicit Application(GUIFactory *factory) : factory(factory) {

    }

    void createUI() {
        button = factory->createButton();
    }

    void paint() {
        button->paint();
    }
};

int main() {
    std::string os;
    std::cin >> os;
    GUIFactory *factory;
    if (os == "Windows") {
        factory = new WinFactory();
    } else if (os == "Mac") {
        factory = new MacFactory();
    }
    auto app = Application(factory);
    app.paint();
}