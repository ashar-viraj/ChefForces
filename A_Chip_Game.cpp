#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'
#define mp make_pair
#define um unordered_map
#define MOD 1000000007
const int x4[4] = {-1, 0, 1, 0}, y4[4] = {0, 1, 0, -1};
const int x8[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, y8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class Food
{
public:
    string food;
    int rating;

    Food(string food, int rating)
    {
        this->food = food;
        this->rating = rating;
    }
};

class myComp
{
public:
    bool operator()(const Food &a, const Food &b)
    {
        if (a.rating == b.rating)
            return (a.food < b.food);
        return (a.rating > b.rating);
    }
};

class FoodRatings
{
public:
    unordered_map<string, priority_queue<Food>, vector<Food>, myComp> map_cuisine;
    unordered_map<string, int> map_food;
    unordered_map<string, string> food_cuisine;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {

        for (int i = 0; i < cuisines.size(); i++)
        {
            Food f(foods[i], ratings[i]);
            map_cuisine[cuisines[i]].push(f);
            map_food[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating)
    {
        map_food[food] = newRating;

        Food f(food, newRating);
        map_cuisine[food_cuisine[food]].push(f);
    }

    string highestRated(string cuisine)
    {

        Food f = map_cuisine[cuisine].top();
        string ans = f.food;
        while (map_food[f.food] != f.rating)
        {
            map_cuisine[cuisine].pop();
            f = map_cuisine[cuisine].top();
            ans = f.food;
        }
        return ans;
    }
};

int main()
{

    return 0;
}