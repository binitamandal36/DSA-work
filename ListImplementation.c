#include<stdlib.h>
#include<string.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

struct book {
   int bId;
   char bname[50];
   float price;
   int stockQty;
};
struct list {
   int count;
   struct book items[MAX];//total capacity of the list to hold items
};
int isFull(struct list*lst){
	return lst->count==MAX-1;
}
int isEmpty(struct list*lst){
	return lst->count==-1;
}
int insertAtEnd(struct list*lst,struct book b){
	if(isFull(lst)){
		printf("List is Full.\n");
		return FALSE;
	} else{
		lst->count++;
		lst->items[lst->count]=b;
		printf("Book inserted at the end.\n");
		return TRUE;
	}
}
int insertAtFront(struct list*lst,struct book b){
	if(isFull(lst)){
		printf("List is full.\n");
		return FALSE;
	} else{
		int i;
		for(i=lst->count;i>=0;i--){
			lst->items[i+1]=lst->items[i];
		}
		lst->items[0]=b;
		lst->count++;
		printf("Book inserted at the front.\n");
		return TRUE;
		}
}
int insertAfterItem(struct list*lst,int itemId, struct book b){
	if(isFull(lst)){
		printf("List is full.\n");
		return FALSE;
	} else{
		int i;
		for(i=0;i<=lst->count;i++){
			if(lst->items[i].bId==itemId){
				int j;
				for(j=lst->count;j>i;j--){
				lst->items[j+1]=lst->items[j];
			}
			lst->items[i+1]=b;
			lst->count++;
			printf("Book inserted after item with ID %d.\n",itemId);
			return TRUE;
			}
		}
		printf("Item with ID %d not found.\n",itemId);
		return FALSE;
	}
}
int insertBeforeItem(struct list*lst,int itemId,struct book b){
	if(isFull(lst)){
		printf("List is full.\n");
		return FALSE;
	} else{
		int i;
		for(i=0;i<=lst->count;i++){
			if(lst->items[i].bId==itemId){
				int j;
				for(j=lst->count;j>=i;j--){
					lst->items[j+1]=lst->items[j];
				}
				lst->items[i]=b;
				lst->count++;
				printf("Book inserted before item with ID %d.\n",itemId);
				return TRUE;
			}
		}
		printf("Item with ID %d not found.\n",itemId);
		return FALSE;
	}
}
int removeFromFront(struct list*lst){
	if(isEmpty(lst)){
		printf("List is empty.\n");
		return FALSE;
	} else{
		int i;
		for(i=0;i<lst->count;i++){
			lst->items[i]=lst->items[i+1];
		}
		lst->count--;
		printf("Book removed from the front.\n");
		return TRUE;
	}
}
int removeFromEnd(struct list*lst){
	if(isEmpty(lst)){
		printf("List is empty.\n");
		return FALSE;
	} else{
		lst->count--;
		printf("Book removed from the end.\n");
		return TRUE;
	}
}
int removeItem(struct list*lst,int itemId){
	if(isEmpty(lst)){
		printf("List is empty.\n");
		return FALSE;
	} else{
		int i;
		for(i=0;i<=lst->count;i++){
			if(lst->items[i].bId==itemId){
				int j;
				for(j=1;j<lst->count;j++){
					lst->items[j]=lst->items[j+1];
				}
				lst->count--;
				printf("Book with ID %d removed.\n",itemId);
				return TRUE;
			}
		}
		printf("Item with ID %d not found.\n",itemId);
		return FALSE;
	}
}
void display(struct list*lst){
	int i;
	if(isEmpty(lst))
	printf("List is empty.\n");
	else {
		printf("List contains:\n");
		printf("B code\tBook Name\tPrice\tQuantity\n");
		for(i=0;i<=lst->count;i++){
			printf("%d\t%s\t%.2f\t%d\n",lst->items[i].bId,lst->items[i].bname,lst->items[i].price,lst->items[i].stockQty);
		}
	}
}
int searchItemById(struct list*lst,int itemId){
   int i;
   for(i=0;i<=lst->count;i++){
   	if(lst->items[i].bId==itemId){
   		printf("Item found:\n");
   		printf("B code\tBook Name\tPrice\tQuantity\n");
   		printf("%d\t%s\t%.2f\t%d\n",lst->items[i].bId,lst->items[i].bname,lst->items[i].price,lst->items[i].stockQty);
   		return TRUE;
	   }
   }
   printf("Item with ID %d not found.\n",itemId);
   return FALSE;
}
int main(){
   struct list lst;
   lst.count=-1;//Initialize count to indicate empty list
   
   int choice;
   struct book b;
   while(1)
   {
   printf("\n1. Insert at End\n2. Insert at Front\n3. Insert After Item\n4. Insert Before Item\n");
   printf("5.Remove from Front\n6. Remove from End\n7. Remove Item\n8. Display\n9. Search by ID\n10. Exit\n");
   printf("Enter your choice:");
   scanf("%d",&choice);
   switch(choice){
	   case 1:
	   	printf("Enter book ID, name, price,and quantity:");
	   	scanf("%d %s %f %d",&b.bId,&b.bname,&b.price,&b.stockQty);
	   	insertAtEnd(&lst,b);
		break;
	   case 2:
	   	printf("Enter book ID, name, price,and quantity:");
	   	scanf("%d %s %f %d",&b.bId,&b.bname,&b.price,&b.stockQty);
	   	insertAtFront(&lst,b);
		break;
	   case 3:
	   	printf("Enter book ID after which to insert,and  then enter book ID,name price,and Quantity:");
	   	scanf("%d  %d %s %f %d",&b.bId,&choice, &b.bname,&b.price,&b.stockQty);
	   	insertAfterItem(&lst,choice,b);
		break;
	   case 4:
	   	printf("Enter book ID after which to insert,and  then enter book ID,name price,and Quantity:");
	   	scanf("%d %d %s %f %d",&b.bId,&choice, &b.bname,&b.price,&b.stockQty);
	   	insertBeforeItem(&lst,choice,b);
		break;
	   case 5:
	   	removeFromFront(&lst);
		break;
	   case 6:
	   	removeFromEnd(&lst);
		break;
	   case 7:
	   	printf("Enter book ID to remove:");
	   	scanf("%d",&choice);
	   	removeItem(&lst,choice);
		break;
	   case 8:
		display(&lst);
		break;
	   case 9:
	    printf("Enter book ID to search:");
	    scanf("%d",&choice);
	    searchItemById(&lst,choice);
	    break;
	    case 10:
	    	exit(0);
		default:
			printf("Invalid choice. Please enter a valid option.\n");
	    }
      }
      return 0;
}

