#include <stdio.h>
#include <stdint.h>

/*Simulated system states*/
typedef enum {
    STATE_IDLE,
    STATE_INIT,
    STATE_RUNNING,
    STATE_ERROR
} system_state_t; //What does typedef do here?
//It creates an alias 'system_state_t' for the enum type, allowing easier usage of the enum type throughout the code.

/*Simulated System flags*/
#define FLAG_READY      (1U << 0)
#define FLAG_ERROR      (1U << 1)

int main(void) {
    system_state_t state = STATE_IDLE;
    uint8_t status_flag = 0;
    int retry_count = 0;
    
    /*------- do-while: retry initialization -------- */
    do 
    {
        printf("Initilializing system... Attempt %d\n", retry_count + 1);
        retry_count++;
    } while (retry_count < 2);

    /*initialization done*/
    status_flag |= FLAG_READY; //What does this line do?
    //This line sets the FLAG_READY bit in the status_flag variable, indicating that the system is ready.
    //This is a bitwise OR operation that updates the status_flag variable.
    //You can change this to FLAG_ERROR to simulate an error condition.
    //status_flag |= FLAG_ERROR;

    /*------------- if-else: check system status ------------- */
    if (status_flag & FLAG_ERROR) //What does this condition check? 
    //It checks if the FLAG_ERROR bit is set in the status_flag variable, indicating an error state.
    //This is a bitwise AND operation that evaluates to true if the FLAG_ERROR bit is set.
    {
        state = STATE_ERROR;
        printf("System Error detected!\n");
    }
    else if (status_flag & FLAG_READY)  //What does this condition check?
    //It checks if the FLAG_READY bit is set in the status_flag variable, indicating that the system is ready.
    //This is a bitwise AND operation that evaluates to true if the FLAG_READY bit is set.
    {
        state = STATE_RUNNING;
        printf("System is running.\n");
    }
    else 
    {
        state = STATE_IDLE;
        printf("System is idle.\n");
    } 

    /* -------- switch-case: state machine -------- */
    switch (state) //What does the switch-case construct do here?
    //It selects and executes a block of code based on the current value of the 'state' variable.
    {
        case STATE_IDLE:
            printf("System is idle\n");
            break;

        case STATE_INIT:
            printf("System initializing\n");
            break;

        case STATE_RUNNING:
            printf("System running\n");

            /* -------- for-loop: process tasks -------- */
            for (int task = 0; task < 3; task++) //What does this for loop do?
            //This for loop iterates through tasks numbered 0 to 2, simulating the processing of each task.
            //It runs the loop body three times, once for each task.
            {
                printf("Running task %d\n", task);
            }
            break; //use of break to exit the switch-case after executing the running state

        case STATE_ERROR:
            printf("System error\n");
            break;

        default:
            printf("Unknown state\n");
            break;
    }

    /*---------- while loop: super loop simulation --------*/
    int loop_counter = 0;
    while(loop_counter < 2) //What does this while loop simulate?
    //This while loop simulates a super loop that continuously runs tasks or checks system status.
    {
        printf("Super loop interation %d\n", loop_counter + 1);
        loop_counter++;
    }

    return 0;

    
}

//This code simulates a simple system state machine using various control flow constructs in C. 
//It demonstrates the use of do-while, if-else, switch-case, for-loop, and while-loop statements to manage system states and tasks.