#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;

public:
    BrowserHistory() {
        currentPage = "Home";  
    }

    void visitPage(string url) {
        backStack.push(currentPage);
        currentPage = url;

        while (!forwardStack.empty())
            forwardStack.pop();

        cout << "Visited: " << currentPage << endl;
    }

    void goBack() {
        if (backStack.empty()) {
            cout << "No Back History!" << endl;
            return;
        }

        forwardStack.push(currentPage);
        currentPage = backStack.top();
        backStack.pop();

        cout << "Back to: " << currentPage << endl;
    }

    void goForward() {
        if (forwardStack.empty()) {
            cout << "No Forward History!" << endl;
            return;
        }

        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();

        cout << "Forward to: " << currentPage << endl;
    }

    void showCurrentPage() {
        cout << "Current Page: " << currentPage << endl;
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string url;

    do {
        cout << "\n===== Browser Menu =====\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                browser.visitPage(url);
                break;

            case 2:
                browser.goBack();
                break;

            case 3:
                browser.goForward();
                break;

            case 4:
                browser.showCurrentPage();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}