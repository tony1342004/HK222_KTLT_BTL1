#include "knight.h"
// dang cho HP chay tu 1 toi 999, nho hon 1 la chet
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    if (level > 10)
        level = 10;
    if (HP > 999)
        HP = 999;
    if (remedy > 99)
        remedy = 99;
    if (maidenkiss > 99)
        maidenkiss = 99;
    if (phoenixdown > 99)
        phoenixdown = 99;

    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

int snt(int a)
{
    int k = 0;
    if (a <= 1)
        return 0;
    else if (a == 2)
        return 1;
    else
    {
        for (int i = 2; i < a; i++)
            if (a % i == 0)
                k++;
        if (k != 0)
            return 0;
        else
            return 1;
    }
}
int fibo(int fb)
{
    int f0 = 1;
    int f1 = 1;
    int f, i;
    if (fb < 0)
        return -1;
    if (fb < 2)
        return 1;
    i = 1;
    while (i < fb)
    {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
        i++;
    }
    return f;
}

int process13(int a, int &c13)
{
    int pow = 1;
    int k = 0;
    int temp = a;
    while (temp > 13)
    {
        temp /= 10;
        k++;
        pow *= 10;
    }
    int result;
    result = a - 13 * pow;
    c13 = k;
    return result;
}

void processFile(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue, int &event, int &k, string &mush_ghost, string &asclepius_pack, string &merlin_pack)
{
    ifstream ifs;
    stringstream ss;
    string line1, line2, line3;
    char inp;
    ifs.open(file_input);
    int j = 1;
    while (ifs.get(inp))
    {
        switch (j)
        {
        case 1:
            line1 += inp;
            if (inp == '\n')
                j++;
            break;
        case 2:
            line2 += inp;
            if (inp == '\n')
                j++;
            break;
        case 3:
            line3 += inp;
            break;
        }
    }
    ss << line1;
    ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown >> event;
    stringstream ss1(line2);
    int evenum;
    int t = 0;
    while (ss1 >> evenum)
        k++;
    string test, line31, line32, line33;
    int m = 1;
    for (int c = 0; c < line3.size(); c++)
    {
        // mush_ghost, asclepius_pack, merlin_pack
        switch (m)
        {
        case 1:
            if (line3[c] != ',' && line3[c] != '<' && line3[c] != '>')
                line31 += line3[c];
            if (line3[c] == ',')
                m++;
            break;
        case 2:
            if (line3[c] != ',' && line3[c] != '<' && line3[c] != '>')
                line32 += line3[c];
            if (line3[c] == ',')
                m++;
            break;
        case 3:
            if (line3[c] != ',' && line3[c] != '<' && line3[c] != '>')
                line33 += line3[c];
            if (line3[c] == ',')
                m++;
            break;
        }
    }
    mush_ghost = line31;
    asclepius_pack = line32;
    merlin_pack = line33;
    ifs.close();
}

string getline2(string file_input)
{
    ifstream ifs;
    string line2;
    char inp;
    ifs.open(file_input);
    int j = 1;
    while (ifs.get(inp))
    {
        switch (j)
        {
        case 1:
            if (inp == '\n')
                j++;
            break;
        case 2:
            line2 += inp;
            if (inp == '\n')
                j++;
            break;
        case 3:
            break;
        }
    }
    ifs.close();
    return line2;
}
void mushghost(string &mush_ghost, int &n2, string &mg_line2)
{
    ifstream ifs;
    stringstream ss;
    char inp;
    ifs.open(mush_ghost);
    string mg_line1;
    int j = 1;
    while (ifs.get(inp))
    {
        switch (j)
        {
        case 1:
            mg_line1 += inp;
            if (inp == '\n')
                j++;
            break;
        case 2:
            mg_line2 += inp;
            if (inp == '\n')
                j++;
            break;
        }
    }
    ss << mg_line1;
    ss >> n2;
    mg_line2 += ",";
    ifs.close();
}

void asclepius(string &asclepius_pack, int &remedy, int &maidenkiss, int &phoenixdown)
{
    ifstream ifs;
    stringstream ss;
    char inp;
    ifs.open(asclepius_pack);
    string ap_line1, ap_line2, ap_line3;
    int j = 1;
    while (ifs.get(inp))
    {
        switch (j)
        {
        case 1:
            ap_line1 += inp;
            if (inp == '\n')
                j++;
            break;
        case 2:
            ap_line2 += inp;
            if (inp == '\n')
                j++;
            break;
        default:
            ap_line3 += inp;
            break;
        }
    }
    int r1 = 0;
    int c1 = 0;
    int count = 0;
    string k;
    r1 = stoi(ap_line1);
    c1 = stoi(ap_line2);
    int k2;
    int arr_ap[100][100];
    int i = 0;
    int m = 0;
    int t = 0;
    ap_line3 += ' ';
    while (ap_line3[t] != '\0')
    {
        k += ap_line3[t];
        if (ap_line3[t] == ' ' || ap_line3[t] == '\n')
        {
            arr_ap[i][m] = stoi(k);
            if (m < c1 - 1)
                m++;
            else if (m == c1 - 1 && i < r1 - 1)
            {
                m = 0;
                i++;
            }
            k = "";
            if (i == r1 - 1 && m == c1 - 1)
                break;
        }
        t++;
    }
    for (int h = 0; h < r1; h++)
    {
        count = 0;
        for (int u = 0; u < c1; u++)
        {
            if (count < 3)
            {
                if (arr_ap[h][u] == 16)
                {
                    count++;
                    remedy++;
                }
                else if (arr_ap[h][u] == 17)
                {
                    count++;
                    maidenkiss++;
                }
                else if (arr_ap[h][u] == 18)
                {
                    count++;
                    phoenixdown++;
                }
            }
        }
    }
    ifs.close();
}

void merlin(string &merlin_pack, int &HP, int &MaxHP)
{
    ifstream ifs;
    char inp;
    ifs.open(merlin_pack);
    int i = 0;
    int n9 = 0;
    int k = 0;
    int nm = 0;
    int ne = 0;
    int nr = 0;
    int nl = 0;
    int ni = 0;
    int nn = 0;
    string line;
    string process;
    int nmerlin = 0;
    while (ifs.get(inp))
        line += inp;
    while (line[i] != '\0')
    {
        process += line[i];
        if (line[i] == '\n' && k == 0)
        {
            n9 = stoi(process);
            k++;
        }
        else if (line[i] == '\n')
        {
            nm = 0;
            ne = 0;
            nr = 0;
            nl = 0;
            ni = 0;
            nn = 0;
            string inp1;
            for (int j = 0; j < process.length(); j++)
            {
                inp1 += process[j];
                if (process[j] == 'M' || process[j] == 'm')
                    nm++;
                if (process[j] == 'E' || process[j] == 'e')
                    ne++;
                if (process[j] == 'R' || process[j] == 'r')
                    nr++;
                if (process[j] == 'L' || process[j] == 'l')
                    nl++;
                if (process[j] == 'I' || process[j] == 'i')
                    ni++;
                if (process[j] == 'N' || process[j] == 'n')
                    nn++;
                if (inp1 == "Merlin" || inp1 == "merlin")
                {
                    nmerlin++;
                    inp1 = "";
                }

                if (nm >= 1 && ne >= 1 && nr >= 1 && nl > 1 && ni >= 1 && nn >= 1)
                {
                    if (nmerlin >= 1)
                    {
                        HP += 3;
                        if (HP > MaxHP)
                            HP = MaxHP;
                    }
                    else
                    {
                        HP += 2;
                        if (HP > MaxHP)
                            HP = MaxHP;
                    }
                }
            }
            process = "";
        }
        i++;
    }
    ifs.close();
}

void damageperevent(int &event, float &baseDamage, int &levelO, int &level, int &HP, int &damage, int &remedy, int &maidenkiss, int &phoenixdown, int &orglevel, int &MaxHP, int i, int &c6, int &c7, string &mush_ghost, string &line2, string &asclepius_pack, string &merlin_pack, int &rescue)
{
    int count19 = 0;
    int count18 = 0;
    int a11 = 0;
    int i12 = 0;
    int temp12;
    orglevel = level;
    int b, n1, s1;
    b = i % 10;
    levelO = i > 6 ? (b > 5 ? b : 5) : b;
    switch (event)
    {
    case 1:
        if (level < levelO)
        {
            baseDamage = 1;
            damage = baseDamage * levelO * 10;
            HP -= damage;
        }
        else if (level > levelO)
            level++;
        break;
    case 2:
        if (level < levelO)
        {
            baseDamage = 1.5;
            damage = baseDamage * levelO * 10;
            HP -= damage;
        }
        else if (level > levelO)
            level++;
        break;
    case 3:
        if (level < levelO)
        {
            baseDamage = 4.5;
            damage = baseDamage * levelO * 10;
            HP -= damage;
        }
        else if (level > levelO)
            level++;
        break;
    case 4:
        if (level < levelO)
        {
            baseDamage = 7.5;
            damage = baseDamage * levelO * 10;
            HP -= damage;
        }
        else if (level > levelO)
            level++;
        break;
    case 5:
        if (level < levelO)
        {
            baseDamage = 9.5;
            damage = baseDamage * levelO * 10;
            HP -= damage;
        }
        else if (level > levelO)
            level++;
        break;
    case 6:
        if (level > levelO || HP == 999 || snt(HP) == 1)
        {
            level += 2;
            level = level > 10 ? 10 : level;
        }
        else if (level < levelO)
        {
            if (c6 == 0)
                c6++;
            if (HP < 5)
                HP = 1;
            else
                HP /= 5;
            if (remedy >= 1)
            {
                c6 = 0;
                HP *= 5;
                remedy--;
            }
        }
        break;
    case 7:
        if (level > levelO || HP == 999 || snt(HP) == 1)
        {
            level += 2;
            level = level > 10 ? 10 : level;
        }
        else if (level < levelO)
        {
            if (c7 == 0)
                c7++;
            level = 1;
            if (maidenkiss >= 1)
            {
                c7 = 0;
                level = orglevel;
                maidenkiss--;
            }
        }
        break;
    case 11:
        n1 = ((level + phoenixdown) % 5 + 1) * 3;
        s1 = 99 * n1 - (n1 - 1) * n1;
        HP += (s1 % 100);
        int pn;
        pn = HP;
        while (a11 == 0 && pn < 999)
        {
            pn++;
            a11 = snt(pn);
        }
        HP = pn;
        HP = (HP > MaxHP) ? MaxHP : HP;
        break;
    case 12:
        while (HP > 1)
        {
            temp12 = HP--;
            while (temp12 > fibo(i12))
                i12++;
            if (temp12 == fibo(i12 - 1))
            {
                HP = temp12;
                break;
            }
        }
        break;
    case 15:
        remedy++;
        remedy = remedy > 99 ? 99 : remedy;
        break;
    case 16:
        maidenkiss++;
        maidenkiss = maidenkiss > 99 ? 99 : maidenkiss;
        break;
    case 17:
        phoenixdown++;
        phoenixdown = phoenixdown > 99 ? 99 : phoenixdown;
        break;
    case 18:
        if (count18 == 0)
        {
            merlin(merlin_pack, HP, MaxHP);
            count18++;
        }
        break;
    case 19:
        if (count19 == 0)
        {
            asclepius(asclepius_pack, remedy, maidenkiss, phoenixdown);
            count19++;
        }
        break;
    case 99:
        if ((snt(HP) == 0 && HP < 999 && level < 10) || ((snt(HP) == 1 || HP == 999) && level < 8))
            rescue = 0;
        else if (((snt(HP) == 1 || HP == 999) && level >= 8) || level == 10)
            level = 10;
        break;
    default:
        if (event > 130)
        {
            int n2;
            string mush, mg_line2;
            int mg[100], mg_3[100];
            int m = 0;
            mushghost(mush_ghost, n2, mg_line2);
            int r = 0;
            int tf1 = 1;
            int tf2 = 1;
            int tf;
            int maxi = 0;
            int mini = 0;
            int maxi2 = 0;
            int mini2 = 0;
            int max2_3x = 0;
            int max2_3i = 0;
            while (mg_line2[r] != '\0')
            {
                if (mg_line2[r] != ',')
                    mush += mg_line2[r];
                if (mg_line2[r] == ',')
                {
                    mg[m] = stoi(mush);
                    mush = "";
                    m++;
                }
                r++;
            }
            for (int i = 0; i < n2; i++)
                mg_3[i] = mg[i];
            for (int i = 0; i < n2; i++)
            {
                if (mg_3[i] < 0)
                    mg_3[i] = -mg_3[i];
                mg_3[i] = (17 * mg_3[i] + 9) % 257;
            }
            int c13 = 0;
            int ms = 0;
            ms = process13(event, c13);
            int arr_mg[100];
            int c = 0;
            while (ms > 0)
            {
                arr_mg[c] = ms % 10;
                ms /= 10;
                c++;
            }
            int max1 = mg[0];
            int min1 = mg[0];
            int k22;
            for (int d = c13 - 1; d >= 0; d--)
            {
                if (HP > MaxHP)
                    HP == MaxHP;
                switch (arr_mg[d])
                {
                case 1:
                    for (int i = 0; i < n2; i++)
                    {
                        if (mg[i] >= max1)
                        {
                            max1 = mg[i];
                            maxi = i;
                        }
                        else if (mg[i] <= min1)
                        {
                            min1 = mg[i];
                            mini = i;
                        }
                    }
                    HP = HP - (maxi + mini);
                    HP = HP > MaxHP ? MaxHP : HP;
                    break;

                case 2:
                    k22 = 0;
                    int max2, imax;
                    max2 = mg[0];
                    for (int i = 0; i < n2; i++)
                    {
                        if (mg[i] > max2)
                        {
                            imax = i;
                            max2 = mg[i];
                        }
                        else if (mg[i] == max2 && k22 == 0)
                        {
                            imax = i;
                            k22++;
                        }
                    }
                    for (int i = 0; i < n2 - 1; i++)
                    {
                        if (mg[i] == mg[i + 1])
                            tf = 0;
                        else
                        {
                            if (i < imax)
                            {
                                if (mg[i] >= mg[i + 1])
                                    tf1 = 0;
                            }
                            else if (i > imax)
                            {
                                if (mg[i] <= mg[i + 1])
                                    tf2 = 0;
                            }
                            tf = tf1 * tf2;
                        }
                        if (tf == 0)
                            break;
                    }
                    int mtx, mti;
                    if (tf == 0)
                    {
                        mtx = -2;
                        mti = -3;
                    }
                    else if (tf == 1)
                    {
                        mtx = max2;
                        mti = imax;
                    }
                    HP = HP - (mtx + mti);
                    HP = HP > MaxHP ? MaxHP : HP;
                    break;
                case 3:
                    int max3, min3;
                    max3 = mg_3[0];
                    min3 = mg_3[0];
                    for (int i = 0; i < n2; i++)
                    {
                        if (mg_3[i] > max3)
                            max3 = mg_3[i];
                        else if (mg_3[i] < min3)
                            min3 = mg_3[i];
                    }
                    for (int i = 0; i < n2; i++)
                    {
                        if (mg_3[i] == max3)
                        {
                            maxi2 = i;
                            break;
                        }
                    }
                    for (int i = 0; i < n2; i++)
                    {
                        if (mg_3[i] == min3)
                        {
                            mini2 = i;
                            break;
                        }
                    }
                    HP = HP - (maxi2 + mini2);
                    HP = HP > MaxHP ? MaxHP : HP;
                    break;
                case 4:
                    int firstmax, secondmax;
                    if (mg_3[0] == mg_3[1] == mg_3[2])
                    {
                        max2_3x = -5;
                        max2_3i = -7;
                    }
                    else if (mg_3[0] > mg_3[1])
                    {
                        firstmax = mg_3[0];
                        secondmax = mg_3[1];
                    }
                    else
                    {
                        firstmax = mg_3[1];
                        secondmax = mg_3[0];
                    }
                    if (firstmax != secondmax)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            if (mg_3[i] > firstmax)
                            {
                                secondmax = firstmax;
                                firstmax = mg_3[i];
                            }
                            else if (mg_3[i] > secondmax && mg_3[i] < firstmax)
                                secondmax = mg_3[i];
                        }
                        for (int i = 0; i < 3; i++)
                        {
                            if (mg_3[i] == secondmax)
                            {
                                max2_3x = secondmax;
                                max2_3i = i;
                                break;
                            }
                        }
                    }
                    HP = HP - (max2_3x + max2_3i);
                    HP = HP > MaxHP ? MaxHP : HP;
                    break;
                default:
                    break;
                }
                if (HP < 0 && phoenixdown==0)
                {
                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    exit(0);
                }
                else if (phoenixdown>0)
                {
                    phoenixdown--;
                    HP = MaxHP;
                }
            }
        }
        break;
    }
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    int MaxHP, event, b, levelO, damage, evnt, c6, c7, orglevel;
    float baseDamage;
    string mush_ghost, asclepius_pack, merlin_pack;
    int k = 0;
    int t = 0;
    int arr[100];
    c6 = 0;
    c7 = 0;
    string line2 = getline2(file_input);
    stringstream ss(line2);
    while (ss >> evnt)
    {
        arr[t] = evnt;
        t++;
    }
    rescue = -1;
    processFile(file_input, HP, level, remedy, maidenkiss, phoenixdown, rescue, event, k, mush_ghost, asclepius_pack, merlin_pack);
    if (HP > 999)
        return;
    MaxHP = HP;
    int h = 0;
    int count = 1;
    for (int i = 0; i < k; i++)
    {
        h = i + 1;
        event = arr[i];
        if (event == 0)
        {
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            return;
        }
        damageperevent(event, baseDamage, levelO, level, HP, damage, remedy, maidenkiss, phoenixdown, orglevel, MaxHP, h, c6, c7, mush_ghost, line2, asclepius_pack, merlin_pack, rescue);
        if (c6 == 4)
        {
            HP *= 5;
            c6 = 0;
        }
        else if (c6 != 0)
            c6++;

        if (c7 == 4)
        {
            level = orglevel;
            c7 = 0;
        }
        else if (c7 != 0)
            c7++;

        if (HP < 1)
        {
            if (phoenixdown != 0)
            {
                phoenixdown--;
                HP = MaxHP;
            }
            else
                rescue = 0;
        }
        if (count == k && HP >= 1)
            rescue = 1;
        if (arr[k - 1] == 6)
            HP = MaxHP;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        if (rescue == 0 || rescue == 1)
            return;
        count++;
    }
}
