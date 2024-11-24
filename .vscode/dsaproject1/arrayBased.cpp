
#include <iostream>
using namespace std;
void display(int num[],int n)
{
    cout<<"[";
    for(int i=0;i<n;i++)
    {

        cout<<num[i]<<" ";
    }
    cout<<"]";
}

void insertAtAnyPosition(int nums[],int n,int position,int number)
{
    for(int i=n-1;i>position-1;i--)
   {
    nums[i]=nums[i-1];
   }
   position--;
   nums[position]=number;

}
void insertAtEnd(int nums[],int n,int number)
{
    nums[n-1]=number;
}
void insertAtFirstPosition(int nums[],int n,int number)
{
    for(int i=n-1;i>0;i--)
    {
        nums[i]=nums[i-1];
    }
        nums[0]=number;
}
void DeleteAtAnyPosition(int nums[],int n,int posi)
{
   
   int i;
   for(i=posi-1;i<n-1;i++)
   {
    nums[i]=nums[i+1];
   }
   nums[i]=0;
}
void deleteAtfirstPostition(int nums[],int n)
{
    
    int i;

    for(i=0;i<n-1;i++)
    {
        nums[i]=nums[i+1];
    }


}
void menu(int arr[],int n)
    {
 cout<<"\t\t menu\n\n1.Insert At Any position\n2.DeleteAtAny\n3.insert At Beginning\n\n4.insert At End\n\n5.delete At First \n";
 int option;
 int val;
  display(arr,n-1);
  cout<<"\n\n";

 cin>>option;
int pos;
int subOption;
 switch(option)
 {
 case 1:


        cout<<"Enter the position\n";
        cin>>pos;
        pos;
        cout<<"enter Value\n";
        cin>>val;
        system("CLS");
        insertAtAnyPosition(arr,n,pos,val);
        display(arr,n);
        cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
        break;
 case 2:
    cout<<"Enter the index\n";
    cin>>pos;
    DeleteAtAnyPosition(arr,n,pos);
    display(arr,n-2);
    cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
    break;
 case 3:
     cout<<"Enter the value\n";
     cin>>val;
     insertAtFirstPosition(arr,n,val);
      display(arr,n);
     cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
     break;
 case 4:

    cout<<"Enter the value\n";
    cin>>val;
    insertAtEnd(arr,n,val);
    display(arr,n);
    cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
            break;
 case 5:
     deleteAtfirstPostition(arr,n);
     display(arr,n-2);
     cout<<"\n1.back\n0.exit";
        cin>>subOption;
        if(subOption==0)
            return;
        if(subOption==1)
            system("ClS");
            menu(arr,n);
            break;


 }
    }
void deleteAtEndPosition(int nums[],int n)
{
    nums[n-2]=nums[n-1];
}

int main()
{
    cout << "enter the number of element\n";
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    system("CLs");
    display(arr,n);
    n++;
    arr[n-1]=0;
    menu(arr,n);

    return 0;
}