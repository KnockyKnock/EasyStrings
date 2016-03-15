#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char* LineCopy(char *str)
{
	int size = 0;
	size = strlen(str);
	char* cop = new char[size];
	for (int i = 0; i < size; i++)
		cop[i] = str[i];
	return cop;
}

void Task7()
{
	const int Size = 100;
	char a[Size];
	cout << "Enter the line" << endl;
	cin.getline(a, Size);
	char * res = LineCopy(a);
	cout << res << endl;
	delete[]res;

}

void Task8()
{
    const int Size = 100;
	char a[Size];
	cout << "Enter the line" << endl;
	cin.getline(a, Size);
	int count = 0;
	int n = strlen(a);
	for (int i = 0; i < n; i++)
    {
        if (a[i]=='1')
            count +=2;
        else
        {
            if (a[i] == '2')
                count +=2;
            else
            {
                if (a[i] == '3')
                    count +=4;
            }
        }
    }
    char* result = new char[n + count];
    int k = 0;
    for (int i = 0; i < n + count; i++, k++)
    {
        if (a[k] == '1')
        {
            result[i] = 'O';
            result[i + 1] = 'n';
            result[i + 2] = 'e';
            i += 2;
        }
        else
        {
            if (a[k] == '2')
            {
                result[i] = 'T';
                result[i + 1] = 'w';
                result[i + 2] = 'o';
                i +=2;
            }
            else
            {
                if (a[k] == '3')
                {
                    result[i] = 'T';
                    result[i + 1] = 'h';
                    result[i + 2] = 'r';
                    result[i + 3] = 'e';
                    result[i + 4] = 'e';
                    i +=4;
                }
                else result[i] = a[k];
            }
        }
    }
    cout << "New string: ";
    cout << result << endl;
    delete[] result;
}

char* ChangeFirstLast(char*line)
{
	int n = strlen(line), h=0;
	char* result = new char[n + 1];
	int i = 0, firstb = 0, firstf = 0, lastb = 0, lastf = 0;
	for (int i = 0; i < n; i++)
	{
		if (line[i] == ' ')
			h++;
	}
	if (h == n)
		return line;
	while ((line[i] == ' ')&&(line[i]!=0))           // переписывает первые пробелы
	{
		result[i] = line[i];
		i++;
    }
	firstb = i; //начало первого слова в line
	while ((line[i] != ' ') && (line[i] != 0))
		i++;
	firstf = i - 1; //конец первого слова в line
	i = n - 1;
	while ((line[i] == ' ') && (line[i] != 0))          // переписывает последние пробелы
	{
		result[i] = line[i];
		i--;
	}
	lastf = i; //конец последнего слова в line
	while ((line[i] != ' ')&&(i!=0))
		i--;
	lastb = i + 1; // начало последнего слова в line
	result[n] = 0;
	for (int j = 0; j < lastf - lastb+1; j++) //последнее слово из line в начало result
		result[firstb + j] = line[lastb + j];
	for (int j = firstf+1; j < lastb; j++) // середина
		result[-(firstf-firstb)+(lastf-lastb)+ j] = line[j];
	for (int j = 0; j < firstf-firstb+1; j++) // первое слово из line в конец result
		result[lastf-j] = line[firstf-j];
	return result;
}

void Task9()
{
	const int Size = 100;
	char str[Size];
	cout << "Enter the line" << endl;
	cin.getline(str, Size);
	cout << "New string:" << endl;
	cout<< ChangeFirstLast(str)<<endl;
}

void Task10()
{
	const int Size = 100;
	char str[Size];
	cout << "Enter the line" << endl;
	cin.getline(str, Size);
	int a[122];
	for (int i = 0; i < 122; i++)
		a[i] = 0;
	int m = 0, n = strlen(str);

	for (int i = 0; i < n; i++)
	{
		m = str[i];
		a[m]++;
	}
	for (int i = 0; i < 122; i++)
	if (((a[i] != 0) && (i>64) && (i<91)) || ((a[i] != 0) && (i>96) && (i<123)))
		cout << char(i) << ": " << a[i] << endl;
}

char* OnlyOddElements(char*line)
{
	int n = strlen(line);
	int m = 0;
	if (n % 2 == 1)
		m = (n + 1) / 2;
	else
		m = n / 2;
	char* result = new char[m+1];
	int j = 0;
	for (int i = 0; i < m; i ++, j+=2)
		result[i] = line[j];
	result[m] = 0;
	return result;
}

void Task11()
{
	const int Size = 100;
	char *str=new char [Size];
	cout << "Enter the line" << endl;
	cin.getline(str, Size);
	char *newstr = new char[Size];
	newstr = OnlyOddElements(str);
	cout << "New string:" << endl;
    cout << newstr;
	cout << endl;
	delete[]str;
	delete[]newstr;
}

int findspace(char* str, int n)
{
	while ((str[n] != ' ') && (str[n] != 0))
	{
		n++;
	}
	return n;
}

void Task12()
{
	int size = -1, linesize = 0, space1 = 0, space2 = 0, k = 0;
	while (size <= 0)
	{
		cout << "Enter the number of rows" << endl;
		cin >> size;
	}
	int const max = 50;
	char**rows = new char*[size+1];
	for (int i = 0; i < size+1; i++)
		rows[i] = new char[max];
	cout << "Enter the rows" << endl;
	for (int i = 0; i < size+1; i++)
		cin.getline(rows[i], max);
	char**newrows = new char*[size + 1];
	for (int i = 0; i < size+1; i++)
		newrows[i] = new char[max];
	for (int i = 0; i < size+1; i++)
	{
		space1 = findspace(rows[i], 0);
		space2 = findspace(rows[i], space1 + 1);
		linesize = strlen(rows[i]);
		newrows[i][0] = rows[i][space1 + 1];
		newrows[i][1] = '.';
		newrows[i][2] = rows[i][space2 + 1];
		newrows[i][3] = '.';
		newrows[i][4] = ' ';
		k = 5;
		for (int j =0 ; j < space1; j++)
		{
			newrows[i][k] = rows[i][j];
			k++;
		}
		newrows[i][k] = 0;
	}
	for (int i = 0; i < size+1; i++)
	{
		linesize = strlen(newrows[i]);
		for (int j = 0; j < linesize; j++)
			cout << newrows[i][j];
		cout << endl;
	}
	for (int i = 0; i < size; i++)
		delete[]newrows[i];
	delete[]newrows;
	for (int i = 0; i < size; i++)
		delete []rows[i];
	delete[]rows;
}

void Task13()
{
	const int size = 10;
	int a[size], k = 0, n = 0;
	cout << "enter an array" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 0)
			k++;
	}
	if (k != 0)
	{
		int *p = 0;
		p = new int[k];
		for (int i = 0; i < size; i++)
		{
			if (a[i] % 2 == 0)
				p[n++] = a[i];
		}
		for (int i = 0; i < k; i++)
			cout << p[i] << " ";
		cout << endl;
		delete[]p;
	}
	else cout << "0" << endl;
}

void Task14()
{
	const int size = 10;
	int a[size];
	int *p = 0;
	int n = 0, k = 0, len = 1;
	cout << "enter an array" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < size; i++)
	{
		k = 0;
		len++;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
				k = 1;
		}
		len -= k;
	}
	p = new int[len];
	for (int i = 0; i < size; i++)
	{
		k = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
				k = 1;
		}
		if (k == 0)
		{
			p[n] = a[i];
			n++;
		}
	}
	for (int i = 0; i < len; i++)
		cout << p[i] << " ";
	cout << endl;
	delete[]p;
}

struct elem
{
	char* fio;
	int sum;
};

void Task15()
{
	int len = 0, lenstr = 0, lenfio = 0;
	const int size = 50;
	char str[size];
	bool checksize = false;
	while (checksize == false)
	{
		checksize = true;
		cout << "Enter the length of array: ";
		cin >> len;
		if (len <= 0)
			checksize = false;

	}
	char **p = 0;
	p = new char*[len];
	for (int i = 0; i < len; i++)
	{
		cout << "Enter the data of participant " << i + 1 << " ";
		cin.getline(str, size);
		lenstr = strlen(str);
		p[i] = new char[lenstr + 1];
		for (int j = 0; j < lenstr; j++)
		{
			p[i][j] = str[j];
		}
		p[i][lenstr] = 0;
	}
	elem *res;
	res = new elem[len];
	int j = 0, k = 0, l = 0;
	char ball[5];
	for (int i = 0; i < len; i++)
	{
		res[i].fio = new char[30];
		k = 0; j = 0, l = 0;

		while (k < 2)                     //переписывает имя
		{
			res[i].fio[j] = p[i][j];
			if (p[i][j] == ' ')
				k++;
			j++;
		}
		res[i].fio[j] = 0;
		while (k < 3)                     // пропускает номер задачи
		{
			if (p[i][j] == ' ')
				k++;
			j++;
		}
		while (j < strlen(p[i]) + 1)      // записывает балл
		{
			ball[l] = p[i][j];
			j++;
			l++;
		}
		ball[l] = 0;
		res[i].sum = atoi(ball);
	}
	for (int i = 0; i < len; i++)      // складывает баллы у повторяющихся имен
	{
		for (int j = 0; j < i; j++)
		{
			if (strcmp(res[j].fio, res[i].fio) == 0)
			{
				res[j].sum += res[i].sum;
				*res[i].fio = '1';
			}
		}
	}
	int max = 0, best = 0, n = 0;
	for (int i = 0; i < len; i++)
	{
		if (res[i].fio != 0 && res[i].sum == max)
		{
			n++;
		}
		if (res[i].fio != 0 && res[i].sum>max)
		{
			max = res[i].sum;
			best = i;
			n = 0;
		}

	}
	if (n != 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (res[i].sum == max)
				cout << res[i].fio << endl;
		}
	}
	else
	{
		cout << res[best].fio << "   " << res[best].sum << endl;
	}
}

struct Payment
{
	char *Name;	// ФИО человека в виде строки
	char *Date; 	// дата в виде строки формата dd.mm.yy
	int Sum;		// сумма платежа
};

Payment* CreateArray(int arraysize)
{
	int const max = 30;
	Payment* arr = new Payment[arraysize];
	char fio[max], data[max];
	int fiosize = 0, datasize = 0, flag=0;
	for (int i = 0; i < arraysize; i++)
	{
	    cin.ignore();
		cout << "Enter the name of the payer     ";
		cin.getline(fio, max);
		cout << endl;
		fiosize = strlen(fio);
		arr[i].Name = new char[fiosize + 1];
		for (int j = 0; j < fiosize; j++)
		{
			arr[i].Name[j] = fio[j];
			flag = j;
		}
		arr[i].Name[flag + 1] = 0;
		cout << "Enter the date of the payment  (dd.mm.yy)    ";
		cin.getline(data, max);
		cout << endl;
		datasize = strlen(data);
		arr[i].Date = new char[datasize + 1];
		for (int j = 0; j < datasize; j++)
		{
			arr[i].Date[j] = data[j];
			flag = j;
		}
		arr[i].Date[flag + 1] = 0;
		cout << "Enter the sum of the payment     ";
		cin >> arr[i].Sum;
		cout <<endl;
	}
	return arr;
}

void PrintArray(Payment* arr, int arraysize)
{
	for (int i = 0; i < arraysize; i++)
	{
		cout << arr[i].Name << "  " << arr[i].Date << "   " << arr[i].Sum << endl;
	}
}

void DeleteArray(Payment* arr, int arraysize)
{
	for (int i = 0; i < arraysize; i++)
	{
		delete[]arr[i].Date;
		delete[]arr[i].Name;
	}
	delete[]arr;
}

void Task16()
{
    int arraysize = 0;
    bool checksize = false;
    while (checksize == false)
    {
		cout << "Enter the size of array" << endl;
		cin >> arraysize;
		if (arraysize > 0)
			checksize = true;
    }
    Payment *arr = new Payment[arraysize];
    arr = CreateArray(arraysize);
    PrintArray(arr, arraysize);
    DeleteArray(arr, arraysize);
}

void Task17()
{
    char symbol = 0;
    int arraysize = 0;
    bool checksize = false;
    while (checksize == false)
    {
		cout << "Enter the size of array" << endl;
		cin >> arraysize;
		if (arraysize >0)
			checksize = true;
    }
    Payment *arr = new Payment[arraysize];
    arr = CreateArray(arraysize);
    cout << "Enter the symbol   ";
    cin >> symbol;
    cout << endl;
    int count = 0;
    for (int i=0; i < arraysize; i++)
    {
        if (arr[i].Name[0] == symbol)
        {
            cout << arr[i].Name << "  " << arr[i].Date << "  " << arr[i].Sum << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Name is not found " << endl;
    }
    DeleteArray(arr, arraysize);
}

void Task18()
{
    int number;
    int arraysize = 0;
    bool checksize = false;
    while (checksize == false)
    {
		cout << "Enter the size of array" << endl;
		cin >> arraysize;
		if (arraysize >0)
			checksize = true;
    }
    Payment *arr = new Payment[arraysize];
    arr = CreateArray(arraysize);
    cout << "Enter the number   ";
    cin >> number;
    cout << endl;
    int count = 0;
    for (int i=0; i < arraysize; i++)
    {
        if (arr[i].Sum > number)
        {
            cout << arr[i].Name << "  " << arr[i].Date << "  " << arr[i].Sum << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Sum is not found " << endl;
    }
    DeleteArray(arr, arraysize);
}

int EqualWords (char* str1, char* str2)
{
    while ((*str1 != 0) || (*str2 != 0))
    {
        if (*str1 != *str2)
            return 0;
        str1++;
        str2++;
    }
    return 1;
}

void Task19()
{
    char* indate;
    int arraysize = 0, datesum = 0;
    bool checksize = false;
    while (checksize == false)
    {
		cout << "Enter the size of array" << endl;
		cin >> arraysize;
		if (arraysize >0)
			checksize = true;
    }
    Payment *arr = new Payment[arraysize];
    arr = CreateArray(arraysize);
    cin.ignore();
    cout << "Enter the date (dd.mm.yy) ";
    cin.getline(indate,12);
    cout << endl;
    int count = 0;
    for (int i=0; i < arraysize; i++)
    {
        if (EqualWords(indate,arr[i].Date) == 1)
        {
            datesum += arr[i].Sum;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Date is not found " << endl;
    }
    else
    {
        cout << "Total sum of payment for " << indate << " = " << datesum << endl;
    }
    DeleteArray(arr, arraysize);
    delete[] indate;
}

void Task20()
{
    int arrDate [12];
    char month[3];
    for (int i = 0; i < 12; i++)
        arrDate[i] = 0;
    int arraysize = 0;
    bool checksize = false;
    while (checksize == false)
    {
		cout << "Enter the size of array" << endl;
		cin >> arraysize;
		if (arraysize >0)
			checksize = true;
    }
    Payment *arr = new Payment[arraysize];
    arr = CreateArray(arraysize);
    int k = 0;
    for (int i=0; i < arraysize; i++)
    {
        month[0] = arr[i].Date[3];
        month[1] = arr[i].Date[4];
        month[2] = 0;
        k = atoi(month);
        arrDate[k-1] ++;
    }
    bool flag = false;
    for (int i=0; i < 12; i++)
    {
        if (arrDate[i] == 0)
        {
            flag = true;
            switch (i)
        {
            case 0: {cout << "January" << endl;
                    break;}
            case 1: {cout << "February" << endl;
                    break;}
            case 2: {cout << "March" << endl;
                    break;}
            case 3: {cout << "April" << endl;
                    break;}
            case 4: {cout << "May" << endl;
                    break;}
            case 5: {cout << "June" << endl;
                    break;}
            case 6: {cout << "Jule" << endl;
                    break;}
            case 7: {cout << "August" << endl;
                    break;}
            case 8: {cout << "September" << endl;
                    break;}
            case 9:{cout << "October" << endl;
                    break;}
            case 10: {cout << "November" << endl;
                    break;}
            case 11: {cout << "December" << endl;
                    break;}
			default: break;
        }
        }
        if (flag)
        {
            cout << "No months without pays";
        }
    }
    DeleteArray(arr, arraysize);
}

int main()
{
    //Task7();
    //Task8();
    //Task9();
    //Task10();
    //Task11();
    //Task12();
    //Task13();
    //Task14();
    //Task15();
    //Task16();
    //Task17();
    //Task18();
    //Task19();
    Task20();
}
