#include <iterator>
#include <vector>
#include <map>
#include <algorithm>


/**
 * @brief Sums up the values of the vector cumulatively, storing cumulative sum
 *        of the vector in a map, where the keys are the unique vector items,
 *        and the value is the last cumulative sum when that value was last
 *        encountered. (example: {4, 5, 4, 6} => {{4, 13}, {5, 9}, {6, 19}}).
 *
 * @param vec vector which is used for the sum operation.
 * @return std::map<int, int> sums - the sums of each cumulation stored in
 *         a map as values, vector values used as keys.
 */
std::map<int, int> cumulativeSums(std::vector<int> v) {
    std::map<int,int> sums;
    sums.insert(std::pair<int,int>(v[0],v[0]));
    for (unsigned int i=1; i<v.size(); ++i) {
        std::map<int, int>::iterator it1=sums.find(v[i]);
        if (it1==sums.end()) {
            std::map<int, int>::iterator it2=sums.find(v[i-1]);
            sums.emplace_hint(it2,v[i],it2->second + v[i]);}
        else {
            std::map<int, int>::iterator it2=sums.find(v[i-1]);
            it1->second=it2->second+v[i];}
    }
    return sums;
}
