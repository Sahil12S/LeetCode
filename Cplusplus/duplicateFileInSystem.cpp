/*
 * Given a list of directory info including directory path, and all the files with contents in this directory,
 * you need to find out all the groups of duplicate files in the file system in terms of their paths.
 * A group of duplicate files consists of at least two files that have exactly the same content.
 * A single directory info string in the input list has the following format:
 * "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
 * It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively)
 * in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
 * The output is a list of group of duplicate file paths. For each group, 
 * it contains all the file paths of the files that have the same content. 
 * A file path is a string that has the following format:
 * "directory_path/file_name.txt"
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

std::vector< std::vector< std::string > > findDuplicate( std::vector< std::string >& paths );

int main(int argc, char const *argv[])
{
    std::vector< std::string > paths = {
        "root/a 1.txt(abcd) 2.txt(efgh)", 
        "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", 
        "root 4.txt(efgh)"
    };

    std::vector< std::vector< std::string > > ans = findDuplicate( paths );

    for( auto dups : ans )
    {
        for( auto file : dups )
        {
            std::cout << file << ", ";

        }
        std::cout << '\n';
    }

    return 0;
}

std::vector< std::vector< std::string > > findDuplicate( std::vector< std::string >& paths )
{
    std::unordered_map< std::string, std::vector< std::string > > contentMap;

    std::stringstream ss;

    for( auto path : paths )
    {
        ss << path;

        std::string dir;
        ss >> dir;
        std::vector< std::string > files;
        std::string file;

        while( ss >> file )
        {
            size_t pos = file.find( '(' );
            if( pos != std::string::npos )
            {
                std::string file_name = file.substr( 0, pos );
                std::string content = file.substr( pos + 1, ( file.length() - ( pos + 1 ) - 1 ) );
                contentMap[content].emplace_back( dir + "/" + file_name );
            }
        }
        ss.clear();
    }

    std::vector< std::vector< std::string > > result;

    for( auto it : contentMap )
    {
        if( it.second.size() > 1 )
        {
            result.emplace_back( it.second );
        }
        // std::cout << '\n';
    }


    return result;
}