/*
1) static int size;
2) newnode
3) Newnode
4) traverse
5) NewNode
6) temp
*/
#include <stdio.h>
#include <stdlib.h>
static int size = 0;

struct node
{
    int data;
    struct node *nextptr;
};

struct node *createnode(int ele)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->nextptr = NULL;
    return newnode;
}

struct node *insertnode(int position, int value, struct node *head)
{
    if (head == NULL) // jab koi head hi nahi hai , to kaha insert karogein . isliye calling the node making machine to make a node.
    {
        head = createnode(value); // naya node baano aur usmein vlaue pass karo jisse ki jo machine dabba banaye usmein vlaue put karte hue
        // jaye aur address provide karte hue jaye null ke taraf
        size = size + 1;
        return head;
    }

    // jab akdam begining mein add karna pade
    if (position == 0) // jab begining mein add karna pade to , naya node ki jaruat to padegi
    {
        struct node *Newnode = createnode(value); // begining mein add karna hai to new node ki need hai , isliye createnode ko bulaya.
        // ki bhaiya app aiye aur node banaiye
        // aur us naye dabbe ka naam hai Newnode
        Newnode->nextptr = head; // jab dabba ban gaya aur hame use shurwat mein dalna hai to jo head banaye the uska address ismein pass karna hoga
        size = size + 1;
        return Newnode;
    }

    struct node *traverse = head; // storing head ki jab ghumna pade LL mein to L na lag jaye head ki
    if (position > size)          // Handle invalid position
    {
        printf("Invalid position. List size is %d\n", size);
        return head;
    }
    for (int i = 0; i < position - 1; i++)
    {
        traverse = traverse->nextptr; // kisi particular location mein add karne ke loye hame traverse karna utne postn tak jitna ya
        // jis position mein add karna hai , LEKIN AKK KAM , jis jagah add karna hai
    }
    struct node *NewNode = createnode(value); // agar koi naya value add karna hai kisi particular postn mein to hame naya dabba lagega
    /*thats why calling the create node ,it will provide me a dabba , jismein vlaue to hai but address null ke taraf point kar raha hai
     kyu ki ye uss create node ki base cond hai ki value dalo dabbe mein aur address null ke taraf*/
    NewNode->nextptr = traverse->nextptr; /*jab naya node mile to abb usemin traverse jo tha , vo us posittion se ak kam tak chal raha
hai , tab means 3 mein add akrna hai to vo chala 2 tak so , 2 se 3 ka address le lenge aur NewNode mein dal denge*/

    traverse->nextptr = NewNode;

    /* now traverse 2nd postn tak chala, joki 3rd postn mein add karna tha.
    but add karne se paahale mein itne pata the ki bhale traverse na chala 3rd postn tak but still uske pass 3rd ka address
    tha 2 se , ki vo chahe to chal saktha tha
    now it mein ki 3rd postn mein 2log point kar rahe hai
    1) NewNode and 2) traverse
    now hame traverse ko point karna hai NewNode ke taraf,isliye
    we shifted the traverse nextptr to NewNode ke address ke taraf
    */

    size = size + 1; // increment of size as we are inc the node one by one
    return head;
}

// Function to delete a node at a specific position
struct node *deletenode(int position, struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return head;
    }

    if (position < 0 || position >= size)
    {
        printf("Invalid position. List size is %d\n", size);
        return head;
    }

    struct node *temp = head;

    if (position == 0)
    { // Deleting the first node
        head = head->nextptr;
        free(temp);
        size--;
        return head;
    }

    struct node *prev = NULL;
    for (int i = 0; i < position; i++)
    {
        prev = temp;
        temp = temp->nextptr;
    }
    prev->nextptr = temp->nextptr;
    free(temp);
    size--;

    return head;
}

void printll(struct node *head) /*passing the head address kyu ki hame data lekar koi fayada hi nahi bcz data se thodi na dusre element
ki data and postn ka pata chalega
isliye to know where the next element is we are passing the head address
and address pass karne se data to mil jayega but data pass karne se dusre element ka address aur na hi data milega */
{
    struct node *temp = head; // storing the head address in the temp, bcz we dont want to loose the HEAD , bin sar ka admi not poosible isliye
    while (temp != NULL)      // address hamare pass hai . aur end of LL tab ayega jab address points to null
    {
        printf("%d->", temp->data); /*address mil gaay tha , ilsiye abb use address se data ko bula lenge , just like jayesh know my home address and to play
        cricket he can come at my home and then call me and i can tell him where yash is
        but suppose ki use sirf mera naam pata ho to chalo ak bar man lete hai usne mujhe bula to liya but vo yash tak access kar payega , nahi*/
        temp = temp->nextptr;       // upadting the pointer of temp as we want to keep moving
    }
}

// main function which is taking input from user and calling the desired function .
int main()
{
    struct node *head = NULL;
    int choice, val, pos;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter position to insert (0 to %d): ", size);
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &val);
            head = insertnode(pos, val, head);
            break;

        case 2:
            printf("Enter position to delete (0 to %d): ", size - 1);
            scanf("%d", &pos);
            head = deletenode(pos, head);
            break;

        case 3:
            printll(head);
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}