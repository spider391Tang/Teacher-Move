//
//  main.cpp
//  Teacher
//
//  Created by HSIN LEI TANG on 13/3/24.
//  Copyright (c) 2013年 HSIN LEI TANG. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>

//================================================
// This problem can be modeled as Graphic problem
// G(V,E)
// Vertex: Counties
// Edge:   Each teacher
//================================================


std::vector<int> teacherVector;
std::set<int> countyVertex;
std::set<std::pair<int, int> > countyFromToEdge;
std::fstream fout;//("/Users/spider391tang/Dropbox/Code/Vincent/out.csv");

void from_to( std::map<int, std::pair <int,int> > map, std::vector<int> vec, int from, int to, int n )
{
    
    if( n == 0 )
    {
        for (int i = 0; i < vec.size(); ++i )
        {
            std::cout << vec[i] << ( i == ( vec.size() -1 ) ?  "":"," );
        }
        std::cout << std::endl;
    }
    else if ( n == 1)
    {
        

        std::map<int, std::pair <int,int> >::iterator it = map.begin();
        for( ; it != map.end(); ++it )
        {
            if( it->second.first == from && it->second.second == to )
            {
                std::map<int, std::pair <int,int> >::iterator findIt = it;
                int findId = it->first;
                
                ++it;
                if( it == map.end() )
                {
                    return;
                }
                vec.push_back( findId );
                map.erase( findIt );
                from_to( map, vec, from, to, n - 1);
                vec.pop_back();
            }
        }
    }
    else
    {
        std::map<int, std::pair <int,int> >::iterator it = map.begin();
        for( ; it != map.end(); ++it )
        {
            if( it->second.first == from  )
            {
                std::map<int, std::pair <int,int> >::iterator findIt = it;
                int findId = it->first;
                int nextFrom = it->second.second;
                
                ++it;
                if( it == map.end() )
                {
                    return;
                }
                
                vec.push_back( findId );
                map.erase( findIt );
                from_to( map, vec, nextFrom, to, n - 1);
                vec.pop_back();
            }
        }
        
    }
    
}


void from_to_graph_theory( std::vector<int> vec, int from, int to, int n )
{
    //int count = 0;
    if( n == 0 )
    {
        for (int i = 0; i < vec.size(); ++i )
        {
            std::cout << std::setw(2) << vec[i] << ( i == ( vec.size() -1 ) ?  "":"," );
            fout << std::setw(2) << vec[i] << ( i == ( vec.size() -1 ) ?  "":"," );
        }
        std::cout << std::endl;
        fout << std::endl;
    }
    else if ( n == 1 )
    {
        if( countyFromToEdge.find( std::make_pair( from, to ) ) != countyFromToEdge.end() )
        {
            vec.push_back( to );
            from_to_graph_theory( vec, from, to, n-1 );
            vec.pop_back();
        }
    }
    else
    {
        for( std::set<int>::iterator it = countyVertex.begin(); it != countyVertex.end(); ++it )
        {
            if(  std::find( vec.begin(), vec.end(), *it ) == vec.end()
               && *it != to
               && countyFromToEdge.find( std::make_pair( from, *it ) ) != countyFromToEdge.end() )
            {
                vec.push_back( *it );
                from_to_graph_theory( vec, *it, to, n-1 );
                vec.pop_back();
            }
        }
    }
}


int main(int argc, const char * argv[])
{

    std::fstream fin("/Users/spider391tang/Dropbox/Code/Vincent/grep_info.csv");
    fout.open("/Users/spider391tang/Dropbox/Code/Vincent/out.csv", std::ios::out);

    std::map<int, std::pair <int,int> > teacherMap;

    
    int moveNumber = 6;
    int teacherFrom = 33;
    int teacherTo = 1;
    
    while( fin )
    {
        int id, from, to;
        fin >> id >> from >> to;
        //std::cout << id << "  " << from << "  " << to << std::endl;
        teacherMap[id] = std::make_pair( from, to );
        
        // Collect the "from county" to "to county" as edge
        countyFromToEdge.insert( std::make_pair( from, to ) );

        // Collect the counties as vetex
        countyVertex.insert( from );
        countyVertex.insert( to );
    }
    
    //for( std::set<int>::iterator it = countyVertex.begin(); it != countyVertex.end(); ++it )
    //{
    //    std::cout << *it << " ";
    //}
    //

    // check last edge
    if( countyFromToEdge.find( std::make_pair( teacherTo, teacherFrom ) ) == countyFromToEdge.end() )
    {
        std::cout << "There is no solution." << std::endl;
    }
    
    std::vector<int> vec;
    vec.push_back( teacherFrom );
    for( std::set<int>::iterator it = countyVertex.begin(); it != countyVertex.end(); ++it )
    {
        if( *it != teacherFrom
           && *it != teacherTo
           && countyFromToEdge.find( std::make_pair( teacherFrom, *it ) ) != countyFromToEdge.end() )
        {
            vec.push_back( *it );
            from_to_graph_theory( vec, *it, teacherTo, moveNumber - 2 );
            vec.pop_back();
        }
    }
    
    
  /*
    std::vector<int> vec;

    std::map<int, std::pair <int,int> >::iterator it = teacherMap.begin();
    for( ; it != teacherMap.end(); ++it )
    {
        if( it->second.first == teacherFrom  )
        {
            std::map<int, std::pair <int,int> > map( teacherMap );
            //std::map<int, std::pair <int,int> >::iterator findIt = it;
            int findId = it->first;
            int nextFrom = it->second.second;
            vec.push_back( findId );
            map.erase( findId );
            from_to( map, vec, nextFrom, teacherTo, moveNumber - 1 );
            vec.pop_back();
        }
    }
   */

    
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}

