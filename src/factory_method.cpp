#include <iostream>

class Button {
public:
    virtual void render() const = 0;

    virtual void onClick(void (*f)()) = 0;

    virtual ~Button() = default;
};

class WindowsButton : public Button {
    void render() const override {
        std::cout << "It a Windows Button";
    }

    void onClick(void (*f)()) override {}
};

class HTMLButton : public Button {
    void render() const override {
        std::cout << "It a HTML Button";
    }

    void onClick(void (*f)()) override {}
};

void closeDialog() {}

class Dialog {
public:
    [[nodiscard]] virtual Button *createButton() const = 0;

    void render() const {
        auto okButton = createButton();
        okButton->onClick(closeDialog);
        okButton->render();
    }

    virtual ~Dialog() = default;
};

class WindowsDialog : public Dialog {
    [[nodiscard]] Button *createButton() const override {
        return new WindowsButton();
    }
};

class WebDialog : public Dialog {
    [[nodiscard]] Button *createButton() const override {
        return new HTMLButton();
    }
};

class Application {
public:
    Dialog *dialog;

    explicit Application(const std::string &os) {
        if (os == "Windows") {
            dialog = new WindowsDialog();
        } else if (os == "Web") {
            dialog = new WebDialog();
        }
    }

    void main() const {
        dialog->render();
    }
};

int main() {
    auto app = Application("Windows");
    app.main();
}