/***********************************
    @���ƣ��ֿ������Ϣ����ϵͳ���
    @author��super-so,
    @create��2019.12.30~2019.12.31
************************************/
#include "head.h"

int main()
{
    int n=0,i=0,user,j=0;                       //n��ʾ���õĺ������ܣ�i��ʾ�ṹ�����
    char a[500]="\n\n\n\n\n\n\n\n\n\n\n\n\n==========================================================================\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n-------------------------�ֿ������Ϣ����ϵͳ���------------------------\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n==========================================================================\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    while(a[j]!='\0')
    {
        Sleep(10);
        printf("%c",a[j]);
        j++;
    }
    user=users();
    if(user==1)
    {
        menu();
        scanf("%d", &n);
        while(n)
        {
            i=dataout();
            hang=i+1;
            switch (n)
            {
            case 1:
                read(i);
                break;
            case 2:
                query(i);
                break;
            case 8:
                user=users();
                break;
            case 9:
                system("cls");
                break;
            default:
                printf("���ù���ԱȨ��\n");
                break;
            }
            if(user==2)
                break;
            menu();
            scanf("%d", &n);
        }
    }
    if(user==2)
    {
        menu();
        scanf("%d", &n);
        while (n)
        {
            i=dataout();
            hang=i+1;
            switch (n)
            {
            case 1:
                read(i);
                break;
            case 2:
                query(i);
                break;
            case 3:
                change(i);
                break;
            case 4:
                sort(i);
                break;
            case 5:
                in(i);
                break;
            case 6:
                out(i);
                break;
            case 7:
                i=clear(i);
                break;
            case 8:
                user=users();
                break;
            case 9:
                system("cls");
                break;
            default:
                printf("�������������0~9֮������֣�����\n");
                break;
            }
            menu();
            scanf("%d", &n);
        }
    }
    return 0;
}

int users()
{
    FILE *fw;
    int n,i=0,j,l=0,k=0;
    char zh[20],password[50];
    printf("��ͨ�û��밴1\n����Ա�û��밴2\n");
    scanf("%d",&n);
    while(n==2)
    {
        printf("\n�������˺�(����000������ͨ�û�����):");
        scanf("%s",&zh);
        if(strcmp(zh,"000")==0)
            return 1;
        printf("����������:");
        password[k] = getch();
        while(password[k]!='\r')
        {
            putchar('*');
            k++;
            password[k] = getch();
        }
        password[k] = '\0';
        printf("\n");
        if ((fw = fopen ("Users.txt", "r")) == NULL)
            printf("�����ڹ���Ա�û�");
        else
        {
            while(!feof(fw))
            {
                fscanf(fw,"%s %s\n",&Users[i].zh,&Users[i].password);
                i++;
            }
            for(j=0; j<i; j++)
            {
                if(strcmp(Users[j].zh,zh)==0&&strcmp(Users[j].password,password)==0)
                {
                    l++;
                    system("cls");
                    printf("��½�ɹ�!!!\n");
                    return 2;
                }
            }
            if(l==0)
            {
                printf("�˺Ż��������");
                continue;
            }
        }
        fclose(fw);
    }
}

void menu()			//�˵�����
{
    system("pause");
    printf("\n\n========================================================================\n");
    printf("------------------------�ֿ������Ϣ����ϵͳ���------------------------\n");
    printf("========================================================================\n\n");
    printf("====================================\n");
    printf("	1:��ʾ����\n");
    printf("	2:��ѯ����\n");
    printf("	3:�޸Ĺ���\n");
    printf("	4:������\n");
    printf("	5:��⹦��\n");
    printf("	6:���⹦��\n");
    printf("	7:��⹦��\n");
    printf("	8:�������Աģʽ\n");
    printf("	9:����\n");
    printf("	0:�˳�\n");
    printf("====================================\n");
    printf("������0~9֮���������");
}

int dataout()		//�ļ����ݴ���ṹ�庯��
{
    int i=0;
    FILE* fp;
    if ((fp = fopen ("data.txt", "r")) == NULL)
    {
        sign=0;
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %s %s %s %s %d\n",&goods[i].num,&goods[i].name,&goods[i].category,&goods[i].specifications,&goods[i].manufactor,&goods[i].area,&goods[i].inventory);
            i++;
        }
    }
    fclose(fp);
    return i;
}

void datain(int i)	//���ݴ����ļ�����
{
    int n;
    FILE *fp;
    fp = fopen ("data.txt", "w");
    for(n=0; n<i; n++)
    {
        fprintf(fp,"%d %s %s %s %s %s %d\n",goods[n].num,goods[n].name,goods[n].category,goods[n].specifications,goods[n].manufactor,goods[n].area,goods[n].inventory);
    }
    fclose(fp);
}

void read(int i)	//�鿴���ݺ���
{
    if(sign==0)
    {
        printf("====================================\n");
        printf("���ļ�ʧ�ܣ�����\n");
        return;
    }
    printf("====================================\n");
    int j;
    printf("����\t���\t����\t���\t���\t����\t����\t�����\n");
    for(j=0; j<i; j++)
    {
        printf("��%d��:\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",j+1,goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
    }
}

void query(int i)	//��ѯ����
{
    printf("====================================\n");
    printf("------------��ѯ���ܽ���------------\n");
    printf("====================================\n");
    int j,k,l=0,n;
    int a1;
    char a2[N];
    printf("����0�˳���ѯ����,����1��ʼ��ѯ��");
    scanf("%d",&k);
    while(k)
    {
        l=0;
        printf("====================================\n");
        printf("������Ҫ��ѯ����ı�Ż����ƻ򳧼�:\n1.���2.���ƻ򳧼�\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("������Ҫ��ѯ�Ļ���ı��\n");
            scanf("%d",&a1);
            for(j=0; j<i; j++)
        {
            if(a1==goods[j].num)
            {
                printf("============================================\n");
                printf("���\t����\t���\t���\t����\t����\t�����\n");
                printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
                l++;
            }
        }
        }

        if(n==2)
        {
            printf("������Ҫ��ѯ�Ļ�������ƻ򳧼�\n");
            scanf("%s",&a2);
        }
        for(j=0; j<i; j++)
        {
            if(strcmp(a2,goods[j].name)==0||strcmp(a2,goods[j].manufactor)==0)
            {
                printf("============================================\n");
                printf("���\t����\t���\t���\t����\t����\t�����\n");
                printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
                l++;
            }
        }
        if(l==0)
        {
            printf("====================================\n");
            printf("δ���ҳ�������ѯ����Ϣ������������\n");
        }
        printf("====================================\n");
        printf("����0�˳���ѯ����,����1��ʼ��ѯ��");
        scanf("%d",&k);
    }
    return;
}

void change(int i)
{
    read(i);
    int x,k;
    char ch[2];
    printf("====================================\n");
    printf("------------�޸Ĺ��ܽ���------------\n");
    printf("====================================\n");
    printf("����0�˳��޸Ĺ���,����1�����޸ģ�");
    scanf("%d",&k);
    while(k)
    {
        printf("====================================\n");
        printf("��������Ҫ�޸ĵ�������");
        int n,m,a;              //n:�޸ĵ�������a���޸���Ϣ���
        scanf("%d",&n);
        m=n-1;					//m���ṹ���±�
        while(n)
        {
            printf("====================================\n");
            printf("1.�޸ı��\n");
            printf("2.�޸�����\n");
            printf("3.�޸����\n");
            printf("4.�޸Ĺ��\n");
            printf("5.�޸ĳ���\n");
            printf("6.�޸Ĳ���\n");
            printf("7.�޸�ȫ��ѡ��\n");
            printf("0.�˳��޸Ľ���\n");
            printf("====================================\n");
            printf("������0~7���������");
            scanf("%d",&a);
            printf("====================================\n");
            printf("��%d��:\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",n,goods[m].num,goods[m].name,goods[m].category,goods[m].specifications,goods[m].manufactor,goods[m].area,goods[m].inventory);
            printf("====================================\n");
            switch(a)
            {
            case 1:
                printf("ԭ��ţ�%d\n",goods[m].num);
                printf("�±��:");
                scanf("%d",&goods[m].num);
                break;
            case 2:
                printf("ԭ���ƣ�%s\n",goods[m].name);
                printf("������:");
                scanf("%s",&goods[m].name);
                break;
            case 3:
                printf("ԭ���%s\n",goods[m].category);
                printf("�����:");
                scanf("%s",&goods[m].category);
                break;
            case 4:
                printf("ԭ���%s\n",goods[m].specifications);
                printf("�¹��:");
                scanf("%s",&goods[m].specifications);
                break;
            case 5:
                printf("ԭ���ң�%s\n",goods[m].manufactor);
                printf("�³���:");
                scanf("%s",&goods[m].manufactor);
                break;
            case 6:
                printf("ԭ���أ�%s\n",goods[m].area);
                printf("�²���:");
                scanf("%s",&goods[m].area);
                break;
            case 7:
                scanf("%d%s%s%s%s%s",&goods[m].num,&goods[m].name,&goods[m].category,&goods[m].specifications,&goods[m].manufactor,&goods[m].area);
                break;
            case 0:
                return;
            default:
                printf("������0~7֮���������");
                break;
            }
            n=0;
        }
        printf("====================================\n");
        printf("����0�˳��޸Ĺ���,����1�����޸ģ�");
        scanf("%d",&k);
    }
    datain(i);
}

void sort(int i)	//������
{
    int n,pass=0,t=0,u,j;
    struct goods trans;
    printf("====================================\n");
    printf("������������ķ�ʽ�ı�ţ��Իس�������\n1.���\n2.���\n0.�˳�\n");
    scanf("%d",&n);
    printf("====================================\n");
    if(n==0)
        return;
    if(n==1)
    {
        for(u=0; u<i-1; u++)
        {
            for(j=u; j<i; j++)
            {
                if(goods[u].num>goods[j].num)
                {
                    trans=goods[u];
                    goods[u]=goods[j];
                    goods[j]=trans;
                }
            }
        }
    }
    if(n==2)
    {
        for(u=0; u<i-1; u++)
        {
            for(j=u; j<i; j++)
            {
                if(strcmp(goods[u].category,goods[j].category)>0)
                {
                    trans=goods[u];
                    goods[u]=goods[j];
                    goods[j]=trans;
                }
            }
        }
    }
    for(j=0; j<i; j++)
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
    datain(i);
}

int in(int i)		//��⺯��
{

    printf("====================================\n");
    printf("------------��⹦�ܽ���------------\n");
    printf("====================================\n");
    struct goods newgood;
    int n,j,s=0;
    printf("�������»���Ļ�����Ϣ\n");
    printf("���\t����\t���\t���\t����\t����\t���������\n");
    scanf("%d\t%s\t%s\t%s\t%s\t%s\t%d",&newgood.num,&newgood.name,&newgood.category,&newgood.specifications,&newgood.manufactor,&newgood.area,&newgood.inventory);
    for(j=0; j<i; j++)
    {
        if(newgood.num==goods[j].num)
        {
            goods[j].inventory=goods[j].inventory+newgood.inventory;
            s=1;
            datain(i);
        }
    }
    if(s==0)
    {
        i++;
        goods[i-1]=newgood;
    }
    datain(i);
    return i;
}

void out(int i)
{
    printf("====================================\n");
    printf("------------���⹦�ܽ���------------\n");
    printf("====================================\n");
    int j,k,l=0,m=0,n,o;
    // char a[N];
    int a;
    printf("����0�˳����⹦�ܣ�����1��ʼ���⣺");
    scanf("%d",&k);
    while(k)
    {
        printf("====================================\n");
        printf("������Ҫ�������ı��:");
        scanf("%d",&a);
        for(j=0; j<i; j++)
        {
            if(a==goods[j].num)
            {
                printf("====================================\n");
                printf("���\t����\t���\t���\t����\t����\t�����\n");
                printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
                l++;
                n=j;
            }
        }
        if(l==0)
        {
            printf("====================================\n");
            printf("δ���ҳ�������ѯ����Ϣ������������\n");
        }
        else
        {
            printf("====================================\n");
            printf("��������Ҫ����Ŀ������");
            scanf("%d",&m);
            goods[n].inventory = goods[n].inventory - m;
            printf("====================================\n");
            printf("ʣ��������%d\n",goods[n].inventory);
        }
        printf("====================================\n");
        printf("����0�˳����⹦�ܣ�����1��ʼ���⣺");
        scanf("%d",&k);
    }
    datain(i);
}

int clear(int i)
{

    char a[N];
    int j,k,t,m,n=0,p,q=i,o;
    int num[N];
    printf("====================================\n");
    printf("------------��⹦�ܽ���------------\n");
    printf("====================================\n");
    printf("������ʾ�ǿ����Ϊ0�Ļ�������Ƿ������һ��������\n");
    for(j=0; j<i; j++)
    {
        if(goods[j].inventory==0)
        {
            num[n]=j;
            n++;
        }
    }
    if(n==0)
    {
        printf("û�п����Ϊ0�Ļ������\n");
        return 0;
    }
    else
    {
        printf("====================================\n");
        printf("����\t���\t����\t���\t���\t����\t����\t�����\n");
        for(o=0; o<n; o++)
        {
            printf("��%d��\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",num[o]+1,goods[num[o]].num,goods[num[o]].name,goods[num[o]].category,goods[num[o]].specifications,goods[num[o]].manufactor,goods[num[o]].area,goods[num[o]].inventory);
        }
    }

    printf("====================================\n");
    printf("����0�˳���⹦�ܣ�����1��ʼ��⣺");
    scanf("%d",&k);
    while(k)
    {
        for(m=n-1; m>=0; m--)
        {
            for(p=num[m]+1; p<i; p++)
            {
                goods[p-1]=goods[p];
            }
            q--;
        }
        printf("====================================\n");
        printf("����0�˳���⹦��,����1��ʼ��⣺");
        scanf("%d",&k);
    }
    datain(q);
    return q;
}
