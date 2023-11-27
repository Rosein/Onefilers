#include<cassert>
#include<iostream>
#include<string>
#include<stack>
#include<set>

std::set<char> opening_braces{'(','[','{'};
std::set<char> closing_braces{')',']','}'};

void run_tests();

bool is_brace(char symbol)
{
    return opening_braces.contains(symbol) || closing_braces.contains(symbol);
}

bool check_if_braces_matches(char candi_open_brace, char candi_close_brace)
{
    const bool kMatches = true;
    auto it_ob = opening_braces.begin();
    auto it_cb = closing_braces.begin();

    for(; it_ob != opening_braces.end(); ++it_ob, ++it_cb)
    {
        if((candi_open_brace == *it_ob) && 
           (candi_close_brace == *it_cb))
        {
            
            return kMatches;
        }
    }

    return !kMatches;
}

bool are_braces_correct(std::string math_expression)
{
    std::stack<char> waiting_braces;

    for(auto& brace : math_expression)
    {
        if(is_brace(brace))
        {
            if(opening_braces.contains(brace))
            {
                waiting_braces.push(brace);
            }

            if(closing_braces.contains(brace))
            {
                if(waiting_braces.empty())
                {
                    waiting_braces.push(brace);
                }
                else if(check_if_braces_matches(waiting_braces.top(), brace))
                {
                    waiting_braces.pop();
                }
            }
        }
    }

    return waiting_braces.empty();
}

int main()
{
    run_tests();
    return 0;
}

void expect_misformulation(const std::string wrong_input)
{
    assert(are_braces_correct(wrong_input) == false);
}

void expect_correctness(const std::string right_input)
{
    assert(are_braces_correct(right_input) == true);
}

void run_tests()
{
    expect_misformulation("({)}");
    expect_misformulation("(){}}");
    expect_misformulation("(){}[{()}(][)[]]");
    expect_misformulation("(x + 1) - {5 * 7} + [0.5 + {(3 * 2) * 5}]*[[3](])");

    expect_correctness("(){}");
    expect_correctness("(){}[{()}][[]]");
    expect_correctness("(x + 1) - {5 * 7} + [0.5 + {(3 * 2) * 5}]*[[3]]");

    std::cout << "Tests passed" << std::endl;
}
