#define BOOST_TEST_MODULE BinarySearchTreeTestsInsertAndLookup
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

#include "BST.h"

// Test Fixtures: empty tree and tree with contents
struct EmptyBinarySearchTree {

    BST b;

    // Setup fixture
    EmptyBinarySearchTree() {
        BOOST_TEST_MESSAGE("Setting up fixture");
        b = BST();
    }

    // Teardown fixture
    ~EmptyBinarySearchTree() {
        BOOST_TEST_MESSAGE("Teardown fixture");
    }
};

struct BigBinarySearchTree {

    BST b;

    // Setup fixture
    BigBinarySearchTree() {
        BOOST_TEST_MESSAGE("Setting up fixture");
        b = BST();

        b.insert(22, "Jane");
        b.insert(22, "Mary");
        b.insert(0, "Harold");
        b.insert(9, "Edward");
        b.insert(37, "Victoria");
        b.insert(4, "Matilda");
        b.insert(26, "Oliver");
        b.insert(42, "Elizabeth");
        b.insert(19, "Henry");
        b.insert(4, "Stephen");
        b.insert(24, "James");
        b.insert(-1, "Edward");
        b.insert(31, "Anne");
        b.insert(23, "Elizabeth");
        b.insert(1, "William");
        b.insert(26, "Charles");
    }

    // Teardown fixture
    ~BigBinarySearchTree()       {
        BOOST_TEST_MESSAGE("Teardown fixture");

    }
};

// INSERT AND LOOKUP WITH A SMALL TREE

BOOST_AUTO_TEST_SUITE(Insert_And_Lookup_Small_Tree)

    BOOST_FIXTURE_TEST_CASE(Insert_And_Lookup_Node, EmptyBinarySearchTree) {

    b.insert(50, "abc");

    std::string output = *b.lookup(50);
    std::string expected = std::string("abc");
    BOOST_CHECK_EQUAL(output, expected);
}

    BOOST_FIXTURE_TEST_CASE(Insert_And_Lookup_Node_Empty_Tree, EmptyBinarySearchTree) {

        std::string* output = b.lookup(51);
        std::string* expected = nullptr;
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Insert_And_Lookup_Node_Not_Found, EmptyBinarySearchTree) {

        b.insert(50, "abc");

        std::string* output = b.lookup(51);
        std::string* expected = nullptr;
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Insert_Two_Nodes, EmptyBinarySearchTree) {

        b.insert(60, "def");
        b.insert(10, "ab");

        std::string output = *b.lookup(60);
        std::string expected = "def";
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Insert_Ten_Nodes, EmptyBinarySearchTree) {

        b.insert(50, "ij");
        b.insert(10, "ab");
        b.insert(100, "st");
        b.insert(60, "kl");
        b.insert(40, "gh");
        b.insert(70, "mn");
        b.insert(90, "qr");
        b.insert(80, "op");
        b.insert(20, "cd");
        b.insert(30, "ef");

        BOOST_CHECK_EQUAL(*b.lookup(60), "kl");
        BOOST_CHECK_EQUAL(*b.lookup(50), "ij");
        BOOST_CHECK_EQUAL(*b.lookup(10), "ab");
        BOOST_CHECK_EQUAL(*b.lookup(100), "st");
        BOOST_CHECK_EQUAL(*b.lookup(60), "kl");
        BOOST_CHECK_EQUAL(*b.lookup(40), "gh");
        BOOST_CHECK_EQUAL(*b.lookup(70), "mn");
        BOOST_CHECK_EQUAL(*b.lookup(90), "qr");
        BOOST_CHECK_EQUAL(*b.lookup(80), "op");
        BOOST_CHECK_EQUAL(*b.lookup(20), "cd");
        BOOST_CHECK_EQUAL(*b.lookup(30), "ef");
    }

    BOOST_FIXTURE_TEST_CASE(Overwrite_Existing_Node, EmptyBinarySearchTree) {

        b.insert(50, "abc");
        b.insert(10, "ab");
        b.insert(50, "def");

        std::string output = *b.lookup(50);
        std::string expected = "def";
        BOOST_CHECK_EQUAL(output, expected);
    }

BOOST_AUTO_TEST_SUITE_END()

// INSERT AND LOOKUP WITH A BIG TREE

BOOST_AUTO_TEST_SUITE(Insert_And_Lookup_Big_Tree)

    BOOST_FIXTURE_TEST_CASE(Testing, BigBinarySearchTree) {
        BOOST_CHECK_EQUAL(*b.lookup(-1), "Edward");
        BOOST_CHECK_EQUAL(*b.lookup(0), "Harold");
        BOOST_CHECK_EQUAL(*b.lookup(1), "William");
        BOOST_CHECK_EQUAL(*b.lookup(4), "Stephen");
        BOOST_CHECK_EQUAL(*b.lookup(9), "Edward");
        BOOST_CHECK_EQUAL(*b.lookup(19), "Henry");
        BOOST_CHECK_EQUAL(*b.lookup(22), "Mary");
        BOOST_CHECK_EQUAL(*b.lookup(23), "Elizabeth");
        BOOST_CHECK_EQUAL(*b.lookup(24), "James");
        BOOST_CHECK_EQUAL(*b.lookup(26), "Charles");
        BOOST_CHECK_EQUAL(*b.lookup(31), "Anne");
        BOOST_CHECK_EQUAL(*b.lookup(37), "Victoria");
        BOOST_CHECK_EQUAL(*b.lookup(42), "Elizabeth");
    }

    BOOST_FIXTURE_TEST_CASE(Insert_And_Lookup_Node, BigBinarySearchTree) {

        b.insert(50, "abc");

        std::string output = *b.lookup(50);
        std::string expected = std::string("abc");
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Insert_And_Lookup_Node_Empty_Tree, BigBinarySearchTree) {

        std::string* output = b.lookup(51);
        std::string* expected = nullptr;
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Insert_And_Lookup_Node_Not_Found, BigBinarySearchTree) {

        b.insert(50, "abc");

        std::string* output = b.lookup(51);
        std::string* expected = nullptr;
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Insert_Two_Nodes, BigBinarySearchTree) {

        b.insert(60, "def");
        b.insert(10, "ab");

        std::string output = *b.lookup(60);
        std::string expected = "def";
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Insert_Ten_Nodes, BigBinarySearchTree) {

        b.insert(50, "ij");
        b.insert(10, "ab");
        b.insert(100, "st");
        b.insert(60, "kl");
        b.insert(40, "gh");
        b.insert(70, "mn");
        b.insert(90, "qr");
        b.insert(80, "op");
        b.insert(20, "cd");
        b.insert(30, "ef");

        BOOST_CHECK_EQUAL(*b.lookup(60), "kl");
        BOOST_CHECK_EQUAL(*b.lookup(50), "ij");
        BOOST_CHECK_EQUAL(*b.lookup(10), "ab");
        BOOST_CHECK_EQUAL(*b.lookup(100), "st");
        BOOST_CHECK_EQUAL(*b.lookup(60), "kl");
        BOOST_CHECK_EQUAL(*b.lookup(40), "gh");
        BOOST_CHECK_EQUAL(*b.lookup(70), "mn");
        BOOST_CHECK_EQUAL(*b.lookup(90), "qr");
        BOOST_CHECK_EQUAL(*b.lookup(80), "op");
        BOOST_CHECK_EQUAL(*b.lookup(20), "cd");
        BOOST_CHECK_EQUAL(*b.lookup(30), "ef");
    }

    BOOST_FIXTURE_TEST_CASE(Overwrite_Existing_Node, BigBinarySearchTree) {

        b.insert(50, "abc");
        b.insert(10, "ab");
        b.insert(50, "def");

        std::string output = *b.lookup(50);
        std::string expected = "def";
        BOOST_CHECK_EQUAL(output, expected);
    }

BOOST_AUTO_TEST_SUITE_END()

// DISPLAY THE TREE

BOOST_AUTO_TEST_SUITE(Display)

// https://stackoverflow.com/questions/5405016/can-i-check-my-programs-output-with-boost-test
struct cout_redirect {
    cout_redirect(std::streambuf* new_buffer) : old(std::cout.rdbuf(new_buffer)) {}

    ~cout_redirect() {
        std::cout.rdbuf(old);
    }
private:
    std::streambuf* old;
};

    BOOST_FIXTURE_TEST_CASE(Print_Empty_Tree, EmptyBinarySearchTree) {

        boost::test_tools::output_test_stream output; {
            cout_redirect guard( output.rdbuf());
            b.displayLTR();
        }

        BOOST_CHECK(output.is_equal(""));
    }

    BOOST_FIXTURE_TEST_CASE(Print_One_Node, EmptyBinarySearchTree) {

        boost::test_tools::output_test_stream output; {
            cout_redirect guard( output.rdbuf());
            b.insert(50, "abc");

            b.displayLTR();
        }

        std::string str = output.str();

        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

        BOOST_CHECK_EQUAL(str, "50:abc");
    }

    BOOST_FIXTURE_TEST_CASE(Print_Ten_Nodes, EmptyBinarySearchTree) {

        boost::test_tools::output_test_stream output; {
            cout_redirect guard( output.rdbuf());
            b.insert(50, "ij");
            b.insert(10, "ab");
            b.insert(100, "st");
            b.insert(60, "kl");
            b.insert(40, "gh");
            b.insert(70, "mn");
            b.insert(90, "qr");
            b.insert(80, "op");
            b.insert(20, "cd");
            b.insert(30, "ef");

            b.displayLTR();
        }

        std::string str = output.str();

        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

        BOOST_CHECK_EQUAL(str, "10:ab20:cd30:ef40:gh50:ij60:kl70:mn80:op90:qr100:st");
    }

BOOST_AUTO_TEST_SUITE_END()

// REMOVE

BOOST_AUTO_TEST_SUITE(Remove)

    BOOST_FIXTURE_TEST_CASE(Remove_Node, BigBinarySearchTree) {

        b.remove(19);

        std::string* output = b.lookup(19);
        std::string* expected = nullptr;
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Node_Empty_Tree, EmptyBinarySearchTree) {

        b.remove(51);

        std::string* output = b.lookup(51);
        std::string* expected = nullptr;
        BOOST_CHECK_EQUAL(output, expected);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Two_Nodes, EmptyBinarySearchTree) {

        b.remove(19);
        b.remove(22);

        BOOST_CHECK_EQUAL(b.lookup(19), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(22), nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Leaf_Node, BigBinarySearchTree) {
        b.remove(1);

        BOOST_CHECK_EQUAL(b.lookup(1), nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_One_Child, BigBinarySearchTree) {
        b.remove(4);

        BOOST_CHECK_EQUAL(b.lookup(4), nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Two_Children, BigBinarySearchTree) {
        b.remove(37);

        BOOST_CHECK_EQUAL(b.lookup(37), nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Ten_Nodes, BigBinarySearchTree) {

        b.remove(22);
        b.remove(0);
        b.remove(9);
        b.remove(37);
        b.remove(4);
        b.remove(42);
        b.remove(19);
        b.remove(4);
        b.remove(24);
        b.remove(-1);
        b.remove(26);

        // Still in the tree
        BOOST_CHECK_EQUAL(*b.lookup(31), "Anne");
        BOOST_CHECK_EQUAL(*b.lookup(23), "Elizabeth");
        BOOST_CHECK_EQUAL(*b.lookup(1), "William");

        // Expecting nullptr
        BOOST_CHECK_EQUAL(b.lookup(22), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(22), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(0), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(9), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(37), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(4), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(42), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(19), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(4), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(24), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(-1), nullptr);
        BOOST_CHECK_EQUAL(b.lookup(26), nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Existing_Node, EmptyBinarySearchTree) {

        b.insert(50, "abc");
        b.insert(10, "ab");
        b.insert(50, "def");

        std::string output = *b.lookup(50);
        std::string expected = "def";
        BOOST_CHECK_EQUAL(output, expected);
    }

BOOST_AUTO_TEST_SUITE_END()

// REMOVE IF

BOOST_AUTO_TEST_SUITE(Remove_If)

    BOOST_FIXTURE_TEST_CASE(Remove_Odd_Nodes, BigBinarySearchTree) {

        b.removeIf([](int i) { return i % 2 != 0; });

        BOOST_CHECK_EQUAL(b.lookup(19), nullptr);
        BOOST_CHECK_EQUAL(*b.lookup(22), "Mary");
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Even_Nodes, BigBinarySearchTree) {

        b.removeIf([](int i) { return i % 2 == 0; });

        BOOST_CHECK_EQUAL(*b.lookup(19), "Henry");
        BOOST_CHECK_EQUAL(b.lookup(22), nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Multiples_Of_Five_No_Removals, BigBinarySearchTree) {

        // Removing 0 as
        b.remove(0);

        b.removeIf([](int i) { return i % 5 == 0; });

        BOOST_CHECK_EQUAL(*b.lookup(-1), "Edward");
        BOOST_CHECK_EQUAL(*b.lookup(1), "William");
        BOOST_CHECK_EQUAL(*b.lookup(4), "Stephen");
        BOOST_CHECK_EQUAL(*b.lookup(9), "Edward");
        BOOST_CHECK_EQUAL(*b.lookup(19), "Henry");
        BOOST_CHECK_EQUAL(*b.lookup(22), "Mary");
        BOOST_CHECK_EQUAL(*b.lookup(23), "Elizabeth");
        BOOST_CHECK_EQUAL(*b.lookup(24), "James");
        BOOST_CHECK_EQUAL(*b.lookup(26), "Charles");
        BOOST_CHECK_EQUAL(*b.lookup(31), "Anne");
        BOOST_CHECK_EQUAL(*b.lookup(37), "Victoria");
        BOOST_CHECK_EQUAL(*b.lookup(42), "Elizabeth");
    }

    BOOST_FIXTURE_TEST_CASE(Remove_Multiples_Of_Seven, BigBinarySearchTree) {

        b.removeIf([](int i) { return i % 7 == 0; });

        BOOST_CHECK_EQUAL(b.lookup(42), nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()

// DEEP COPY

BOOST_AUTO_TEST_SUITE(Deep_Copy)

    BOOST_FIXTURE_TEST_CASE(Deep_Copy_Tree, BigBinarySearchTree) {
        BST newTree = BST(b);

        BOOST_CHECK(newTree.lookup(22) != b.lookup(22));
        BOOST_CHECK(*newTree.lookup(22) == *b.lookup(22));
    }

    BOOST_FIXTURE_TEST_CASE(Deep_Copy_Operator, BigBinarySearchTree) {
        BST newTree = b;

        BOOST_CHECK(newTree.lookup(22) != b.lookup(22));
        BOOST_CHECK(*newTree.lookup(22) == *b.lookup(22));
    }

BOOST_AUTO_TEST_SUITE_END()

// MOVE

BOOST_AUTO_TEST_SUITE(Move)

    BOOST_FIXTURE_TEST_CASE(Move_Constructor, BigBinarySearchTree) {
        BST newTree = std::move(b);

        BOOST_CHECK(b.lookup(22) == nullptr);
        BOOST_CHECK(*newTree.lookup(22) == "Mary");
    }

    BOOST_FIXTURE_TEST_CASE(Move_Assignment_Operator, BigBinarySearchTree) {
        BST newTree = b;

        BOOST_CHECK(b.lookup(22) == nullptr);
        BOOST_CHECK(*newTree.lookup(22) == "Mary");
    }

BOOST_AUTO_TEST_SUITE_END()