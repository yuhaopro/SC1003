#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Constants
#define MAX 5

//Structure
typedef struct
{
    int roomID;
    int status;
    char customerName[20]; 
}Room;

//Function Prototypes
void listOccupiedRooms();
void assignRoom();
void removeRoom();
void findCustomer();

//Global Variables
int Quit = 0;
int input;
Room RoomList[MAX];


int main()
{
    //generate hotel rooms
    for (int i = 0; i < MAX; i++)
    {
        RoomList[i].roomID = i + 1;
        RoomList[i].status = 0;
        memset(RoomList[i].customerName, 0, sizeof(RoomList[i].customerName));
    }
    
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");
    
    while (Quit == 0)
    {
        printf("Enter your choice:\n");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                listOccupiedRooms();
                break;
            case 2:
                assignRoom();
                break;
            case 3:
                removeRoom();
                break;
            case 4:
                findCustomer();
                break;
            case 5:
                Quit = 1;
                printf("Program Ended\n");
                break;
        }
    }
}


void listOccupiedRooms()
{
    int RoomNotEmpty = 0;
    printf("listOccupiedRooms(): \n");
    //no room is occupied
    for (int i = 0; i < MAX; i++)
    {
        if (RoomList[i].status == 1)
        {
            printf("roomID: %d\n", RoomList[i].roomID);
            printf("customer name: %s\n", RoomList[i].customerName);
            RoomNotEmpty = 1;
        }
    }
    if (RoomNotEmpty == 0)
    {
        printf("The hotel is empty\n");
    }
}

void assignRoom()
{
    int roomID, HotelFull = 1;
    int AskRoomID = 1;
    char str[20];
    printf("assignRoom():\n");

    for (int i = 0; i < MAX; i++)
    {
        if (RoomList[i].status != 1)
        {
            HotelFull = 0;
            break;
        }
    }
    
    if (HotelFull == 1)
    {
        printf("The hotel is full\n");
        return;
    }

    while(AskRoomID == 1)
    {
        printf("Enter a roomID between 1 and 5: \n");
        scanf("%d", &roomID);
        //Checks range of roomID
        if (roomID < 1 || roomID > 5)
        {
            continue;
        }
        //check if roomID exists and not occupied
        for (int i = 0; i < MAX; i++)
        {
            if (roomID == RoomList[i].roomID && RoomList[i].status == 0)
            {
                //ask user to enter customerName
                printf("Enter customer name: \n");
                scanf(" %20[^\n]", str);
                // fflush(stdin);
                // fgets(str, 20, stdin);
                // if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n'))
                // {
                //     str[strlen(str) - 1] = '\0';
                // }
                //copies string over to customer
                strcpy(RoomList[i].customerName,str);
                //Turn Off the Loop
                AskRoomID = 0;
                RoomList[i].status = 1;
                //printf("Customer Name Entered: %s\n", RoomList[i].customerName);
                printf("The room has been assigned successfully \n");
                break;
            }
            else if (roomID == RoomList[i].roomID && RoomList[i].status == 1)
            {
                //Occupied Room
                printf("Occupied! Enter another roomID\n");
                //Quits for loop and asks for roomID
                break;
            }
        }
    }
}

void removeRoom()
{
    int HotelEmpty = 1;
    int invalidRoomID = 1;
    int input;
    printf("removeRoom():\n");
    for (int i = 0; i < MAX; i++)
    {
        if (RoomList[i].status == 1)
        {
            HotelEmpty = 0;
        }
    }

    if (HotelEmpty == 1)
    {
        printf("All the rooms are empty\n");
        return;
    }


    while (invalidRoomID == 1)
    {
        printf("Enter a roomID between 1 and 5: \n");
        scanf("%d", &input);
        if (input < 1 || input > 5)
        {
            continue;
        }

        for (int i = 0; i < MAX; i++)
        {
            if (RoomList[i].roomID == input)
            {
                //check if room empty
                if (RoomList[i].status == 0)
                {
                    printf("Empty! Enter another roomID for removal\n");
                }
                else if (RoomList[i].status == 1)
                {
                    RoomList[i].status = 0;
                    memset(RoomList[i].customerName, 0, sizeof(RoomList[i].customerName));
                    invalidRoomID = 0;
                    printf("Removal is successful\n");
                    break;
                }
            }
        }
        
    }
}

void findCustomer()
{
    char name[20];
    char lowerCustomerName[20];
    int nameFound = 0;
    memset(name, 0, sizeof(name));
    printf("findCustomer():\n");
    printf("Enter customer name: \n");
    scanf(" %20[^\n]", name);
    // fflush(stdin);
    // fgets(name, 20, stdin);
    // if ((strlen(name) > 0) && (name[strlen(name) - 1] == '\n'))
    // {
    //     name[strlen(name) - 1] = '\0';
    // }

    //convert to lower case for input
    for (int i = 0; i < strlen(name); i++)
    {
        name[i] = tolower(name[i]);
    }
    

    for (int i = 0; i < MAX; i++)
    {
        memset(lowerCustomerName, 0, sizeof(lowerCustomerName));
        for(int j = 0; j < strlen(RoomList[i].customerName); j++)
        {
            lowerCustomerName[j] = tolower(RoomList[i].customerName[j]);
        }
        //printf("lowerCustomerName: %s\n", lowerCustomerName);
        //returns 0 if string is equal
        //printf("name: %d, customer: %d: strcmp: %d\n",sizeof(name), sizeof(RoomList[i].customerName),(name, RoomList[i].customerName));
        if (strcmp(name, lowerCustomerName) == 0)
        {
            printf("The target customer name is found\n");
            printf("roomID: %d\n", RoomList[i].roomID);
            printf("customer name: %s\n", RoomList[i].customerName);
            nameFound = 1;
            break;
        }
    }

    if (nameFound == 0)
    {
        printf("The target customer name is not found\n");
    }
}