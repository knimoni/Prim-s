#include<iostream>
#include <cstdlib>

using namespace std;
class prims
{
private:
    int n;
    int graph_edge[250][4];
    int g;
    int tree_edge[250][4];
    int t;
    int s;

    int T1[50], t1;
    int T2[50], t2;
public:
    void input();
    int findset(int);
    void algorithm();
    void output();
};
void prims::input()
{
    cout << "========== Program MST dengan Algoritma Prim ==========\n\n";
    cout << "Masukkan banyaknya titik : "; cin >> n;
    g = 0;
    cout << "masukkan jarak antar titik: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cout << " ( " << i << " , " << j << " ) = ";
            int w;
            cin >> w;
            if (w != 0)
            {
                g++;
                graph_edge[g][1] = i;
                graph_edge[g][2] = j;
                graph_edge[g][3] = w;
            }
        }
    }
}

int prims::findset(int x)
{
    for (int i = 1; i <= t1; i++)
        if (x == T1[i])
            return 1;
    for (int i = 1; i <= t2; i++)
        if (x == T2[i])
            return 2;
    return -1;
}

void prims::algorithm()
{
    t = 0;
    t1 = 1;
    T1[1] = 1;
    t2 = n - 1;
    int i;
    for (i = 1; i <= n - 1; i++)
        T2[i] = i + 1;
    cout << "\n======================================================\n\n";
    while (g != 0 && t != n - 1)
    {
        int min = 9999;
        int p;
        int u, v, w;
        for (i = 1; i <= g; i++)
        {
            bool flag1 = false, flag2 = false;

            if (findset(graph_edge[i][1]) != findset(graph_edge[i][2]))
            {
                if (min > graph_edge[i][3])
                {
                    min = graph_edge[i][3];
                    u = graph_edge[i][1];
                    v = graph_edge[i][2];
                    w = graph_edge[i][3];
                    p = i;
                }
            }
        }
        cout << "Jalur yang dipilih adalah :( " << u << " , " << v << " )  " << endl;
        cout << "Sisi yang terdapat titik ( " << u << " , " << v << " ) : " << endl;
        for (int l = p; l < g; l++)
        {
            graph_edge[l][1] = graph_edge[l + 1][1];
            graph_edge[l][2] = graph_edge[l + 1][2];
            graph_edge[l][3] = graph_edge[l + 1][3];
        }
        g--;

        t++;
        tree_edge[t][1] = u;
        tree_edge[t][2] = v;
        tree_edge[t][3] = w;

        t1++;
        int m{};
        if (findset(v) == 2)
        {
            T1[t1] = v;
            m = v;
        }
        else if (findset(u) == 2)
        {
            T1[t1] = u;
            m = u;
        }
        int x;
        for (x = 1; T2[x] != m; x++);
        for (; x < t2; x++)
            T2[x] = T2[x + 1];
        t2--;

        for (i = 1; i <= g; i++)
            cout << " ( " << graph_edge[i][1] << " , " << graph_edge[i][2] << " ) = " << graph_edge[i][3] << endl;
        cout << endl << endl;
    }

}

void prims::output()
{
    cout << "\nJalur-jalur yang dipilih =\n";
    for (int i = 1; i <= t; i++)
        cout << " ( " << tree_edge[i][1] << " , " << tree_edge[i][2] << " ) = " << tree_edge[i][3] << endl;
}

int main(int argc, char* argv[])
{
awal:
    prims obj;
    obj.input();
    obj.algorithm();
    obj.output();

    char L;
    cout << "\n\nMasukkan ulang data (y/n) ";
    cin >> L;
    if (L == 'y') {
        system("cls");
        goto awal;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}