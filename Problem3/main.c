#include <stdio.h>
#include "../klnstl/klnstrqueue.h"
#include "consts.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{
    // Queues for parked vehicles and waiting vehicles.
    KLNStringQueue vp_queue_parked;
    KLNStringQueue vp_queue_entrance;
    KLNStringQueueCreateQueue(&vp_queue_parked);
    KLNStringQueueCreateQueue(&vp_queue_entrance);

    // Loop for all vehicle movements.
    char vp_movement_flag;
    char vp_vin[VP_VEHICLE_VIN_LENGTH];
    while (scanf(" %c %s", &vp_movement_flag, vp_vin) == 2)
    {
        if (vp_movement_flag == VP_VEHICLE_MOVEMENT_FLAG_ARRIVAL)
        {
            // Arrival of a vehicle to the park
            if (vp_queue_parked.size >= VP_MAX_PARKING_SPACE)
            {
                // If maximum number of vehicles are parked, add the vehicle to the entrance queue.
                KLNStringQueueAppend(&vp_queue_entrance, vp_vin, VP_VEHICLE_VIN_LENGTH);
                printf("Arrival(A): %s | No room. | Paused at entrance queue.\n", vp_vin);
            }
            else
            {
                // If there is enough parking space, add to the parked queue.
                KLNStringQueueAppend(&vp_queue_parked, vp_vin, VP_VEHICLE_VIN_LENGTH);
                printf("Arrival(A): %s | Parking space allocated. | Parked.\n", vp_vin);
            }
        }
        else if (vp_movement_flag == VP_VEHICLE_MOVEMENT_FLAG_DEPART)
        {
            // Departure of a vehicle from the park.
            // Queue to hold temprary departures (which happens to get the desired car out.)
            KLNStringQueue vp_queue_temp_outs;
            KLNStringQueueCreateQueue(&vp_queue_temp_outs);

            // Allocates memory for a VIN variable for usage across the code.
            char *vin_temp = (char *)malloc(sizeof(char) * VP_VEHICLE_VIN_LENGTH);

            // Loop through the queue, eliminating the departing vehicle.
            bool vp_departing_vin_found = false;
            while (KLNStringQueueServe(&vp_queue_parked, &vin_temp))
            {
                // If the read VIN is not the same as departing vehicle, add to the temporary outs queue.
                if (strcmp(vin_temp, vp_vin) == 0)
                {
                    vp_departing_vin_found = true;
                }
                else
                {
                    KLNStringQueueAppend(&vp_queue_temp_outs, vin_temp, VP_VEHICLE_VIN_LENGTH);
                }
            }

            // If the vehicle has been found in the park,
            if (vp_departing_vin_found)
            {
                // Print departure info.
                printf("Departure(D): %s | Departed the park.\n", vp_vin);

                // Restores back the other vehicles from west.
                while (KLNStringQueueServe(&vp_queue_temp_outs, &vin_temp))
                {
                    KLNStringQueueAppend(&vp_queue_parked, vin_temp, VP_VEHICLE_VIN_LENGTH);
                }

                // Enters a vehicle from entrance queue since a vehicle departed. (Automatically doesn't execute if no vehicle was found for departing VIN)
                while (vp_queue_parked.size < VP_MAX_PARKING_SPACE && KLNStringQueueServe(&vp_queue_entrance, &vin_temp))
                {
                    KLNStringQueueAppend(&vp_queue_parked, vin_temp, VP_VEHICLE_VIN_LENGTH);
                    printf("Arrival(A): %s | Parking space allocated | Parked | From Waiting List.\n", vin_temp);
                }

                // Deallocates the temprary variable.
                free(vin_temp);

                // Destroys the temporary queues.
                KLNStringQueueDestroy(&vp_queue_temp_outs, VP_VEHICLE_VIN_LENGTH);
            }
            // If the vehicle hasn't been found in the park,
            else
            {
                // Prints that the vehicle given is not found.
                printf("Departure(D): %s | No such vehicle parked.\n", vp_vin);
            }
        }
        else if (vp_movement_flag == VP_EXIT_FLAG)
        {
            break;
        }
    }

    // Destroys the queues.
    KLNStringQueueDestroy(&vp_queue_entrance, VP_VEHICLE_VIN_LENGTH);
    KLNStringQueueDestroy(&vp_queue_parked, VP_VEHICLE_VIN_LENGTH);
}
