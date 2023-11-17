#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void FindOptimalPath_InTriangle();
void SumPath_InTriangle(int** Trg, int** Sum, int n);
void Enter_Trg(int** Arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << Arr[i][j] << " ";
        cout << endl;
    }
}

void Chain();

int main()
{
    setlocale(LC_ALL, "Ru");
    //FindOptimalPath_InTriangle();
    Chain();

    return 0;
}





void Chain() // Задача с цепочками
{

    int size1 = 100, size2 = 100;
    while (size1 > 30)
    {
        cout << "Введите длинну первой строки, до 30\n";
        cin >> size1;
    }
    while (size2 > 30)
    {
        cout << "Введите длинну второй строки, до 30\n";
        cin >> size2;
    }

    int** CountCoincid = new int* [size1];
    bool** Coincid = new bool* [size1];
    for (int i = 0; i < size1; i++)
    {
        CountCoincid[i] = new int [size2];
        Coincid[i] = new bool[size2];
    }


    string Str1 = { 'a', 'g', 't', 'g', 'c', 'g', 'a', 'a', 'c', 'a', 'g', 't', 'c', 'c', 'g', 'a', 'a', 'c', 'a', 'g', 'a', 't', 'c', 't', 'g', 'a', 'g', 'a', 'c', 'a'};
    string Str2 = { 'c', 'a', 'c', 'a', 't', 't', 'g', 'a', 'c', 'g', 'g', 'a', 'c', 't', 'g', 't', 'c', 'a', 'g', 't', 'c', 'a', 'a', 'g', 't', 'c', 'a', 'a', 'g', 't'};
    
    //========= Filing =============
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (Str1[i] == Str2[j])
                Coincid[i][j] = 1;
            else
                Coincid[i][j] = 0;
        }
    }

    for (int j = 0; j < size2; j++)
        CountCoincid[0][j] = Coincid[0][j];
    for (int i = 0; i < size1; i++)
        CountCoincid[i][0] = Coincid[i][0];
    for (int i = 1; i < size1; i++)
    {
        for (int j = 1; j < size2; j++)
        {
            if (Coincid[i][j] == 1)
                CountCoincid[i][j] = CountCoincid[i - 1][j - 1] + 1;
            else
                CountCoincid[i][j] = max(CountCoincid[i - 1][j], CountCoincid[i][j - 1]);
        }
    }




    cout << "Массив совпадений:\n";
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << Coincid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Массив CountCoincid:\n";
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << CountCoincid[i][j] << " ";
        }
        cout << endl;
    }

   /* cout << "Введите цепочку днк из символов:\na, c, g, t\n";
    for (int i = 0; i < size; i++)
    {
        cin >> Str1[i];
        while (true)
        {

            switch (Str1[i])
            {
            case 'a':
                flag1 = true;
            case 'g':
                flag1 = true;
            case 'c':
                flag1 = true;
            case 't':
                flag1 = true;
            default:
                flag1 = false;
            }
            if (flag1 = true)
                break;

            
        }
    }*/
    

    cout << Str1 << endl;
    cout << Str2 << endl;
}



//------------------  Algorithm for finding the maximum path in a triangle  ------------------
void FindOptimalPath_InTriangle()
{
    int height = INT_MAX;

    while (height > 10000)
    {
        cout << "Введите высоту треугольника\n";
        cin >> height;
    }

        int** Triangle = new int* [height];
    for (int i = 0; i < height; i++)
        Triangle[i] = new int[height];
    int** SumPath = new int* [height];
    for (int i = 0; i < height; i++)
        SumPath[i] = new int[height];

    //======= Completion arrey ======= 
    for (int i = 0; i < height; i++)
        for (int j = 0; j < height; j++)
        {
            if (j <= i)
                Triangle[i][j] = rand() % 9 + 1;
            else
                Triangle[i][j] = 0;

        }

    cout << "Массив\n";
    Enter_Trg(Triangle, height);

    SumPath_InTriangle(Triangle, SumPath, height);

    cout << "Массив сумм\n";
    Enter_Trg(SumPath, height);
    cout << "the end";
}
void SumPath_InTriangle(int** Trg, int** Sum, int n)
{
    int* Path = new int[n];
    int maxP, indP;
    Sum[0] = Trg[0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (Sum[i - 1][j] > Sum[i - 1][j - 1])
            {
                Sum[i][j] = Trg[i][j] + Sum[i - 1][j];
            }
            else
            {
                Sum[i][j] = Trg[i][j] + Sum[i - 1][j - 1];
            }
        }

    
    for (int j = n - 1; j >= 0; j--)
    {
        maxP = 0;
        for (int i = 0; i < n; i++)
            if (maxP < Sum[j][i])
            {
                maxP = Sum[j][i];
                indP = i;
            }
        Path[j] = indP;
    }

    cout << "Максимальный путь равен " << Sum[n - 1][Path[n - 1]] << endl;
    cout << "Путь равен\n i,j";
    for (int i = 0; i < n; i++)
        cout << " -> " << i << "," << Path[i];
    cout << endl;
}



//void FindOptimalPath_InTriangle()
//{
//    int height = INT_MAX, size = 1;
//
//    vector <vector <int>> Triangle;
//    vector <vector <int>> SumPath;
//
//    while (height > 10000)
//    {
//        cout << "Введите высоту треугольника\n";
//        cin >> height;
//    }
//    vector <int> NumLeaves(height - 1);
//    NumLeaves[0] = 1;
//    for (int i = 0; i < height - 1; i++)
//    {
//        size = size + i;
//        NumLeaves[i] = size;
//    }
//
//    // ====== Enter Lists =======
//    for (int i = 0; i < height - 1; i++)
//        cout << "NumLeaves[i] = " << NumLeaves[i] << "\n";
//    cout << "size " << size << endl;
//
//    Triangle.resize(size, vector <int>(1));
//    for (int i = 0; i < size; i++)
//    {
//        Triangle[i].resize(NumLeaves[i]);
//
//    }
//    
//    cout << "the end";
//    /*for (int i = 0; i < size; i++)
//        for (int j = 0; j < NumLeaves[i]; j++)
//            Triangle[i][j] = rand() % 10;*/
//
//    /*cout << "Treugol'nik\n";
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < NumLeaves[i]; j++)
//            cout << Triangle[i][j] << " ";
//        cout << endl;
//    }*/
//}
