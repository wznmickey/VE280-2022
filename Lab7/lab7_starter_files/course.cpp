/*
 * VE280 Lab 7, SU2022
 * Created by cyx on 20-5-22.
 * Modified by tongjin on June 26th, 2022.
 */

#include "course.h"
#include <cstdlib>
#include <iostream>

void TechnicalCourse::updateTask( const std::string &type, int index, int dueMonth, int dueDay )
// REQUIRES: dueMonth and dueDay are in normal range.
// MODIFIES: this
// EFFECTS: if Task index of type already exists in tasks, updates its dueMonth & dueDay ;
//          otherwise, adds Task i of type at the end of tasks if tasks is not full,
//          throw an exception if tasks is full
{
    // TODO: implement this function
    for ( auto i = 0; i < numTasks; i++ )
    {
        if ( ( tasks [ i ].type == type ) && ( tasks [ i ].index == index ) )
        {
            tasks [ i ].dueDay   = dueDay;
            tasks [ i ].dueMonth = dueMonth;
            return;
        }
    }
    if ( numTasks >= sizeTasks )
    {
        throw TooManyTasks( );
    }
    tasks [ numTasks ].dueDay   = dueDay;
    tasks [ numTasks ].dueMonth = dueMonth;
    tasks [ numTasks ].index    = index;
    tasks [ numTasks ].type     = type;
    numTasks++;
    if ( ( type == "Lab" ) || ( type == "Project" ) )
    {
        std::cout << courseCode << " " << type << " " << index << " is released! Submit it via oj!" << std::endl;
    }
    else
    {
        std::cout << courseCode << " " << type << " " << index << " is released! Submit it via canvas!" << std::endl;
    }

    return;
}

void TechnicalCourse::finishTask( const std::string &type, int index, int finishMonth, int finishDay )
// REQUIRES: Task index of type is in tasks. finishMonth and finishDay are in normal range.
// MODIFIES: this
// EFFECTS: removes Task index of type
{
    // TODO: implement this function
    for ( auto i = 0; i < numTasks; i++ )
    {
        if ( ( tasks [ i ].type == type ) && ( tasks [ i ].index == index ) )
        {
            if ( ( finishMonth * 64 + finishDay <= tasks [ i ].dueMonth * 64 + tasks [ i ].dueDay ) )
            {
                std::cout << courseCode << " " << tasks [ i ].type << " " << tasks [ i ].index << " is finished!" << std::endl;
            }
            else
            {
                std::cout << courseCode << " " << tasks [ i ].type << " " << tasks [ i ].index << " is overdue!" << std::endl;
            }
            for ( auto j = i; j + 1 < numTasks; j++ )
            {
                tasks [ j ] = tasks [ j + 1 ];
            }
            numTasks--;
            return;
        }
    }
}

void TechnicalCourse::print( ) const
{
    std::cout << courseCode << std::endl;
    for ( int i = 0; i < numTasks; ++i )
    {
        std::cout << tasks [ i ].type << " " << tasks [ i ].index << ": " << tasks [ i ].dueMonth << "/" << tasks [ i ].dueDay << std::endl;
    }
}

void UpperLevelTechnicalCourse::updateTask( const std::string &type, int index, int dueMonth, int dueDay )
// REQUIRES: dueMonth and dueDay are in normal range.
// MODIFIES: this
// EFFECTS: If Task index of type does not exist in tasks,
//          adds Task i of type according to its due date if tasks is not full, throw an exception if tasks is full.
//          If Task index of type already exists in tasks,
//          updates its position in tasks & dueMonth & dueDay if its dueMonth/dueDay is changed,
//          do nothing if its dueMonth/dueDay is unchanged.
{
    // TODO: implement this function
    for ( auto k = 0; k < numTasks; k++ )
    {
        if ( ( tasks [ k ].type == type ) && ( tasks [ k ].index == index ) )
        {
            tasks [ k ].dueDay   = dueDay;
            tasks [ k ].dueMonth = dueMonth;
            for ( auto i = 0; i < numTasks; i++ )
            {
                for ( auto j = 0; j < numTasks - 1; j++ )
                {
                    if ( tasks [ j ].dueMonth * 64 + tasks [ j ].dueDay > tasks [ j + 1 ].dueMonth * 64 + tasks [ j + 1 ].dueDay )
                    {
                        std::swap( tasks [ j ], tasks [ j + 1 ] );
                    }
                }
            }
            return;
        }
    }
    if ( numTasks >= sizeTasks )
    {
        throw TooManyTasks( );
    }
    tasks [ numTasks ].dueDay   = dueDay;
    tasks [ numTasks ].dueMonth = dueMonth;
    tasks [ numTasks ].index    = index;
    tasks [ numTasks ].type     = type;
    numTasks++;

    if ( type == "Team Project" )
    {
        std::cout << courseCode << " " << type << " " << index << " is released! Submit it via github!" << std::endl;
    }
    else
    {
        if ( ( type == "Lab" ) || ( type == "Project" ) )
        {
            std::cout << courseCode << " " << type << " " << index << " is released! Submit it via oj!" << std::endl;
        }
        else
        {
            std::cout << courseCode << " " << type << " " << index << " is released! Submit it via canvas!" << std::endl;
        }
    }
    for ( auto i = 0; i < numTasks; i++ )
    {
        for ( auto j = 0; j < numTasks - 1; j++ )
        {
            if ( tasks [ j ].dueMonth * 64 + tasks [ j ].dueDay > tasks [ j + 1 ].dueMonth * 64 + tasks [ j + 1 ].dueDay )
            {
                std::swap( tasks [ j ], tasks [ j + 1 ] );
            }
        }
    }
    return;
}

Course *create( const std::string &classType, const std::string &courseCode )
{
    if ( classType == "Technical" )
    {
        return new TechnicalCourse( courseCode );
    }
    else if ( classType == "Upper Level Technical" )
    {
        return new UpperLevelTechnicalCourse( courseCode );
    }
    else
    {
        return nullptr;
    }
}

Course *create( const std::string &classType, const std::string &courseCode, const int &size )
{
    if ( classType == "Technical" )
    {
        return new TechnicalCourse( courseCode, size );
    }
    else if ( classType == "Upper Level Technical" )
    {
        return new UpperLevelTechnicalCourse( courseCode, size );
    }
    else
    {
        return nullptr;
    }
}
