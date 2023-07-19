#include <stdio.h>
struct SeatNo
{                                              //Declaring a struct datatype SeatNo for storing seat values with a char for row and int for col
    char row;
    int col;
};
void TimeSlot()                                //To dislay available time slots
{
    printf("\n=======================================================\n");
    printf("Please enter your preferred time slot\n");
    printf("---------------------------------------\n");
    printf("1- 13.00- 16.00\n");
    printf("2- 17.00 - 20.00\n");
    printf("=======================================================\n");
}

void SeatArrangement(char seat[][10])                  //To assign the structure of seats
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 && j == 0)
            {
                seat[i][j] = ' ';
            }
            else if (i == 0 && j >= 1)
            {
                seat[i][j] = j + 48;
            }
            else if (j == 0 && i >= 1)
            {
                seat[i][j] = i + 64;
            }
            else
                seat[i][j] = '*';
        }
    }
}

void DisplaySeatCategories()                               //To display the categaro of seats available
{
    printf("\n=======================================================\n");
    printf("Seat slots and their prices\n");
    printf("--------------------------------------\n");
    printf("1 - VIP (Fare - 600 per ticket)\n");
    printf("2 - Premium (Fare - 400 per ticket)\n");
    printf("3 - Normal (Fare - 200 per ticket)\n");
    printf("=======================================================\n\n");
}

void DisplaySeatArrangement(char seat[][10])             //To dislay the seat arrangement,called once before booking and once after booking
{                                                        //to show the selected seats. The booked seats are shown with 'B'.                     
    for (int i = 0; i < 10; i++)
    {
        if (i == 1)
        {
            printf("        VIP\n");
        }
        else if (i == 3)
        {
            printf("        PREMIUM\n");
        }
        else if (i == 6)
        {
            printf("        NORMAL\n");
        }
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", seat[i][j]);
            if (j == 0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("        SCREEN\n");
}

void change(int i, int j, char seat[][10])   //To change status of selected seat by user to 'B' which indicates seat booked
{
    i = i - 65 + 1;
    seat[i][j] = 'B';
}
void book(int nt, char seat[][10])          //to book the seats according to user input
{
    int cost = 0;                           //cost variable to store the final price user has to pay.
    for (int i = 1; i <= nt; i++)
    {
    rebook:
        printf("\nPlease enter the category of seat %d you want : ", i);     //Taking input the category of seat from the user
        int cat;
        scanf("%d", &cat);
        printf("Please enter your preferred seat no. : ");            //Taking input the preferred seat no. in the selected category
        fflush(stdin);
        struct SeatNo id;
        scanf("%c%d", &id.row, &id.col);
        printf("%c%d\n", id.row, id.col);
        if (seat[id.row - 64][id.col] == 'B')             //If seat no. selected has a value='B' indiacating seat already booked, redirecting
                                                          //user to select seats again           
        {
            printf("Seat already occupied.Please choose again\n\n");
            goto rebook;
        }
        else                                              //If seat available for booking, then booking seats by changing selected seat no.
        {                                              //to 'B' using change() and updating the value of cost variable accordingly              
            if (cat == 1 && id.row >= 'A' && id.row <= 'B')
            {
                int price = 600;
                cost = cost + price;
                change(id.row, id.col, seat);
            }
            else if (cat == 2 && id.row >= 'C' && id.row <= 'E')
            {
                int price = 400;
                cost = cost + price;
                change(id.row, id.col, seat);
            }
            else if (cat == 3 && id.row >= 'F' && id.row <= 'I')
            {
                int price = 200;
                cost = cost + price;
                change(id.row, id.col, seat);
            }
            else                          //If seat no. selected does not match with the selected category, Then redirect to choose seats again 
            {
                printf("The seat no does not match with the seat categrory. Please choose and the seat No. again \n\n");
                goto rebook;
            }
        }
    }
    printf("\n=======================================================\n");   //Dispalying the message seats booked and showing final price.
    printf("Your seats are booked.\n");
    printf("Total Fare : Rs%d\n", cost);
    printf("=======================================================\n\n");
}

void hall1(char seata[][10], char seatb[][10])
{
    int nt;
    printf("\nYour selected movie is Gehraiyaan\n");
    TimeSlot();                                           //calling TimeSlot() to display available time slots
    int t;
time:
    scanf("%d", &t);                                       //input users preferred time slot
    if (t == 1)
        printf("\nYour selected time slot is 13.00-16.00\n");
    else if (t == 2)
        printf("\nYour selected time slot is 17.00-20.00\n");
    else
    {
        printf("Invalid input. Enter time slot again : \n");         //If invalid time slot entered,taking input nfor time again
        goto time;
    }
    printf("\n");
    printf("\n=======================================================\n");
    printf("The following seats are currently available\n");
    printf("--------------------------------------------\n");
    (t == 1) ? DisplaySeatArrangement(seata) : DisplaySeatArrangement(seatb);  //Displaying current status of seats for selected time slot 1
    printf("=======================================================\n");

    DisplaySeatCategories();                                                   //Displaying category of seats

    printf("\n=======================================================\n");
    printf("Please enter the number of tickets\n");                           //Taking input number of tickets user wants to book
    printf("--------------------------------------\n");
    scanf("%d", &nt);

    (t == 1) ? book(nt, seata) : book(nt, seatb);            //redirecting to book() with required arguments according to selected time slot
                                                            //Here, seata refers to time slot 1 and seatb refers to time slot 2  
    (t == 1) ? DisplaySeatArrangement(seata) : DisplaySeatArrangement(seatb);   //Displaying seat arrangements after tickets booked.
}
void hall2(char seata[][10], char seatb[][10])
{
    int nt;
    printf("\nYour selected movie is RRR\n");
    TimeSlot();
    int t;
time:
    scanf("%d", &t);
    if (t == 1)
        printf("\nYour selected time slot is 13.00-16.00\n");
    else if (t == 2)
        printf("\nYour selected time slot is 17.00-20.00\n");
    else
    {
        printf("Invalid input. Enter time slot again :");
        goto time;
    }

    printf("\n");
    printf("\n=======================================================\n");
    printf("The following seats are currently available\n");
    printf("--------------------------------------------\n");
    (t == 1) ? DisplaySeatArrangement(seata) : DisplaySeatArrangement(seatb);
    printf("=======================================================\n");

    DisplaySeatCategories();

    printf("\n=======================================================\n");
    printf("Please enter the number of tickets\n");
    printf("--------------------------------------\n");
    scanf("%d", &nt);

    (t == 1) ? book(nt, seata) : book(nt, seatb);
    (t == 1) ? DisplaySeatArrangement(seata) : DisplaySeatArrangement(seatb);
}
void hall3(char seata[][10], char seatb[][10])
{
    int nt;
    printf("\nYour selected movie is The Kashmir Files\n");
    TimeSlot();
    int t;
time:
    scanf("%d", &t);
    if (t == 1)
        printf("\nYour selected time slot is 13.00-16.00\n");
    else if (t == 2)
        printf("\nYour selected time slot is 17.00-20.00\n");
    else
    {
        printf("Invalid input. Enter time slot again : \n");
        goto time;
    }

    printf("\n");
    printf("\n=======================================================\n");
    printf("The following seats are currently available\n");
    printf("--------------------------------------------\n");
    (t == 1) ? DisplaySeatArrangement(seata) : DisplaySeatArrangement(seatb);
    printf("=======================================================\n");

    DisplaySeatCategories();

    printf("\n=======================================================\n");
    printf("Please enter the number of tickets\n");
    printf("--------------------------------------\n");
    scanf("%d", &nt);

    (t == 1) ? book(nt, seata) : book(nt, seatb);
    (t == 1) ? DisplaySeatArrangement(seata) : DisplaySeatArrangement(seatb);
}

int main()
{
    char seat1a[10][10]; char seat1b[10][10];   //Here seat1a refers to seat arrangement of movie 1 time 1(13.00-16.00), seat2b refers to seat 
    char seat2a[10][10]; char seat2b[10][10];   //arrangement of movie 2 time 2(17.00-20.00).
    char seat3a[10][10]; char seat3b[10][10];
    SeatArrangement(seat1a); SeatArrangement(seat2a); SeatArrangement(seat3a);
    SeatArrangement(seat1b); SeatArrangement(seat2b); SeatArrangement(seat3b);
    change('A', 6, seat1a); change('F', 1, seat1a); change('D', 5, seat1a); change('G', 3, seat1a); //Pre-booking some random seats
    change('A', 6, seat2a); change('C', 1, seat2a); change('G', 5, seat2a);
    change('D', 6, seat3a); change('G', 1, seat3a); change('I', 5, seat3a); change('B', 3, seat3a);
    change('D', 6, seat1b); change('G', 1, seat1b); change('I', 5, seat1b);
    change('A', 6, seat2b); change('F', 1, seat2b); change('D', 5, seat2b); change('G', 3, seat2b);
    change('A', 6, seat3b); change('C', 1, seat3b); change('G', 5, seat3b);
    while (1)
    {
        int m;
        printf("\n\n\n=======================================================\n");
        printf("Welcome to our movie ticket booking system!!\n");                         //Program start
        printf("=======================================================\n\n");
        printf("=======================================================\n");
        printf("Movies screening currently\n");                                           //Displying currently screening movies
        printf("---------------------------\n");
        printf("Hall 1-Gehraiyaan\n");
        printf("Hall 2-RRR\n");
        printf("Hall 3-The Kashmir Files\n");
        printf("=======================================================\n\n");
    restart:
        printf("Choose the movie you want to book\n");                                     //take input for movie of user's choice
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            hall1(seat1a, seat1b);                                                    //If movie chosen 1, redirect to function hall1()
            break;
        case 2:
            hall2(seat2a, seat2b);                                                   //If movie chosen 2, redirect to function hall2()
            break;
        case 3:
            hall3(seat3a, seat3b);                                                  //If movie chosen 3, redirect to function hall3()           
            break;
        default:
            printf("Invalid input\n");                                              //If invalid input, redirecting to pragram start
            goto restart;
        }
        printf("\n=======================================================\n");
        printf("       Thanks!!\n Enjoy your movie experience");
        printf("\n=====================================================\n");
         char cont[100];
         printf("\nENTER any key to Continue  ");
         scanf("%s", &cont);
        printf("\n=======================================================\n");
        printf("1- Continue for next booking\n");
        printf("0- Exit and reset the System\n");
        printf("---------------------------\n");
        printf("Enter value:-");                                //If input 1, pramgram runs again with seat booked in storage
        int reset;                                              //If input 0, loops break and all data resets.
        scanf("%d", &reset);
        printf("=======================================================\n\n");
        if (!reset)
            break;
    }
}
