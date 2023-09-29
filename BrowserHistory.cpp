#include<bits/stdc++.h>
using namespace std;

/* <-----READ ME----->
   -> Assume no closing of Tabs takes place
   -> No multiple tabs concept (Only single tab in the Browser)
*/
class BrowserHistory
{
    stack<string> Stack1, Stack2;
    
    // Browser Forward Operation
    public:
    void Forward()
    {
        if(Stack2.empty()) cout << "No More Websites.." << endl;
        else
        {
            string nameofWeb = Stack2.top();
            Stack2.pop();
            Stack1.push(nameofWeb);
            cout << "Current Website : " << nameofWeb << endl;
        }
    }

    //Browser Backward Operation
    void Backward()
    {
        if(Stack1.empty()) cout << "No More Websites..." << endl;
        else
        {
            string nameofWeb = Stack1.top();
            Stack1.pop();
            Stack2.push(nameofWeb);
            cout << "Current Website : " << Stack1.top() << endl;
        }
    }

    //Browser Visit Operation
    void Visit(string website)
    {
        if(!Stack2.empty())
        {
            Stack2 = stack<string>();
        }
        Stack1.push(website);
        cout << "Current Website : " << website << endl;
    }
};

int main()
{
    BrowserHistory History;
    cout << "Type names to perform these Operations : " << endl;
    cout << "-->Forward : forward\n-->Backward : backward\n-->Visit : visit\n-->Close the Tab : exit" << endl;
    string Operation;
    while(Operation != "exit")
    {
        cout << "Enter here: ";
        cin >> Operation;
        transform(Operation.begin(), Operation.end(), Operation.begin(), ::tolower);
        if(Operation == "forward") History.Forward();
        else if(Operation == "backward") History.Backward();
        else if(Operation == "visit") 
        {
            string webName;
            cout << "Enter the Website to reach : ";
            cin >> webName;
            History.Visit(webName);
        }
        else if(Operation == "exit")
        {
            cout << "Tab Closed" << endl;
            break;
        }
        else {
            cout << "Enter the valid Operation.." << endl;
        }
    }
    return 0;
}

