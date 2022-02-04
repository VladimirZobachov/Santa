#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    vector<string> listOfPresenter;
    vector<string> listOfRecipient;

    string path = "startList.txt";
    ifstream fin;
    fin.open(path);

    if (!fin.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        string str;
        int i;

        while (getline(fin, str))
        {
            listOfPresenter.push_back(str);
            i++;
        }
    }

    listOfRecipient = listOfPresenter;

    shuffle (listOfRecipient.begin(), listOfRecipient.end(), std::random_device());

    ofstream fout;
    string pathResult = "ResultFile.txt";
    fout.open(pathResult);

    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        for (int i=0; i<listOfRecipient.size(); i++){

            vector<string>::iterator itOfPres = listOfPresenter.begin();
            vector<string>::iterator itOfRecip = listOfRecipient.begin();

            if(*(itOfPres + i)==*(itOfRecip + i)){
                while(*(itOfPres + i)==*(itOfRecip + i)) {
                    shuffle((itOfRecip + i), listOfRecipient.end(), std::random_device());
                }
            }

            fout << *(itOfPres + i)<< ":" << *(itOfRecip + i) << endl;
    }

    fout.close();

    }

    return 0;
}
