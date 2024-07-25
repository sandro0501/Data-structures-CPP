
/* ************************************************************************** */

#include "test.hpp"

using namespace std;

/* ************************************************************************** */

void mytest() {
  //myTestExercise1();
  //myTestExercise2();
  myTestExercise3();
}

/* ************************************************************************** */

void myTestExercise1() {
    cout << "***** My test Exercise 1 *****" << endl << endl;
    testVectorUnsignedLongValues();
    testVectorDoubleValues();
    testVectorStringValues();
    testList();
    testListUnsignedLongValues();
    testListDoubleValues();
    testListStringValues();
    testStack();
    testQueue();
}

void testVectorUnsignedLongValues() {

  cout << "Testing Vector (unsigned long values)" << endl << endl;

  bool verified_test;
  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned long> dist(1, 10000);

  
  unsigned long vector_size = dist(gen);
  // Specific constructor
  lasd::Vector<unsigned long> test_vector(vector_size);

  // Size
  if (vector_size == test_vector.Size()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Vector size is: " << test_vector.Size() << ". Test result: " << (verified_test ? "Passed" : "Error") << endl;

  // Test copy constructor
  lasd::Vector<unsigned long> copy_vector(test_vector);
  if (copy_vector == test_vector) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "2. Are vectors equal? (Copy constructor). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Fill the array with values
  for(unsigned long i = 0; i < test_vector.Size(); i++) {
    test_vector[i] = dist(gen);
  }

  // Test operators == and !=
  lasd::Vector<unsigned long> copy_vector_two(test_vector);
  if (copy_vector_two == test_vector) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "3. Are vectors equal? (Operator == ). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  lasd::Vector<unsigned long> test_vector_two(copy_vector_two.Size());
  for(unsigned long i = 0; i < test_vector_two.Size(); i++) {
    test_vector_two[i] = 0;
  }

  if (copy_vector_two != test_vector_two) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "4. Are vectors not equal? (Operator !=). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Copy assignment
  lasd::Vector<unsigned long> test_vector_three;
  test_vector_three = test_vector;
  if (test_vector == test_vector_three) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "5. Are vectors equal? (Copy assignment). Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  // Clear
  test_vector.Clear();
  try{
    cout << test_vector[5];
    verified_test = false; 
  } catch (...) {
    verified_test = true;
    cout << "6. Clearing array. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  }
  
  // Size after Clear
  if(test_vector.Size() == 0) {
    verified_test = true; 
  } else {
    verified_test = false;
  }
  cout << "7. Testing size of array after Clear. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Resize
  test_vector.Resize(20);
  if (test_vector.Size() == 20) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "8. Testing resize of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Front and Back
  unsigned long front = 0;
  unsigned long back = 0;

  for(unsigned long i = 0; i < 20; i++) {
    test_vector[i] = dist(gen);
    if (i == 0) { 
      front = test_vector[i]; 
    } else if (i == 19) { 
      back = test_vector[i]; 
    }
  }

  if(front == test_vector.Front()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "9. Testing Front of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  if(back == test_vector.Back()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "10. Testing Back of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Test sortable array
  unsigned long sortable_vector_size = 10;
  lasd::SortableVector<unsigned long> test_sortable_vector(sortable_vector_size);
  cout << "11. Testing sortable array. "<< endl; 
  cout << "Sortable vector elements: [ ";

  for(unsigned long i = 0; i<test_sortable_vector.Size(); i++){
    test_sortable_vector.lasd::Vector<unsigned long>::operator[](i) = dist(gen);
    cout << test_sortable_vector.lasd::Vector<unsigned long>::operator[](i) << " ";
  }
  cout << "]" << endl;
  cout << "Sorting vector elements: [ ";
  test_sortable_vector.Sort();
  for(unsigned long i = 0; i<test_sortable_vector.Size(); i++){
    cout << test_sortable_vector.lasd::Vector<unsigned long>::operator[](i) << " ";
  }
  cout << "]" << endl;
  cout << "Front is: " << test_sortable_vector.Front() << endl;
  cout << "Back is: " << test_sortable_vector.Back() << endl;

  cout << endl << endl;

}

void testVectorDoubleValues() {

  cout << "Testing Vector (double values)" << endl << endl;

  bool verified_test;
  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned long> distx(1, 10000);
  uniform_real_distribution<double> dist(1.0, 10000.0);

  
  unsigned long vector_size = distx(gen);
  // Specific constructor
  lasd::Vector<double> test_vector(vector_size);

  // Size
  if (vector_size == test_vector.Size()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Vector size is: " << test_vector.Size() << ". Test result: " << (verified_test ? "Passed" : "Error") << endl;

  // Test copy constructor
  lasd::Vector<double> copy_vector(test_vector);
  if (copy_vector == test_vector) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "2. Are vectors equal? (Copy constructor). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Fill the array with values
  for(unsigned long i = 0; i < test_vector.Size(); i++) {
    test_vector[i] = dist(gen);
  }

  // Test operators == and !=
  lasd::Vector<double> copy_vector_two(test_vector);
  if (copy_vector_two == test_vector) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "3. Are vectors equal? (Operator == ). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  lasd::Vector<double> test_vector_two(copy_vector_two.Size());
  for(unsigned long i = 0; i < test_vector_two.Size(); i++) {
    test_vector_two[i] = 0.0;
  }

  if (copy_vector_two != test_vector_two) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "4. Are vectors not equal? (Operator !=). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Copy assignment
  lasd::Vector<double> test_vector_three;
  test_vector_three = test_vector;
  if (test_vector == test_vector_three) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "5. Are vectors equal? (Copy assignment). Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  // Clear
  test_vector.Clear();
  try{
    cout << test_vector[5];
    verified_test = false; 
  } catch (...) {
    verified_test = true;
    cout << "6. Clearing array. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  }
  
  // Size after Clear
  if(test_vector.Size() == 0) {
    verified_test = true; 
  } else {
    verified_test = false;
  }
  cout << "7. Testing size of array after Clear. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Resize
  test_vector.Resize(20);
  if (test_vector.Size() == 20) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "8. Testing resize of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Front and Back
  double front = 0;
  double back = 0;

  for(unsigned long i = 0; i < 20; i++) {
    test_vector[i] = dist(gen);
    if (i == 0) { 
      front = test_vector[i]; 
    } else if (i == 19) { 
      back = test_vector[i]; 
    }
  }

  if(front == test_vector.Front()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "9. Testing Front of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  if(back == test_vector.Back()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "10. Testing Back of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Test sortable array
  unsigned long sortable_vector_size = 10;
  lasd::SortableVector<double> test_sortable_vector(sortable_vector_size);
  cout << "11. Testing sortable array. "<< endl; 
  cout << "Sortable vector elements: [ ";

  for(unsigned long i = 0; i<test_sortable_vector.Size(); i++){
    test_sortable_vector.lasd::Vector<double>::operator[](i) = dist(gen);
    cout << test_sortable_vector.lasd::Vector<double>::operator[](i) << " ";
  }
  cout << "]" << endl;
  cout << "Sorting vector elements: [ ";
  test_sortable_vector.Sort();
  for(unsigned long i = 0; i<test_sortable_vector.Size(); i++){
    cout << test_sortable_vector.lasd::Vector<double>::operator[](i) << " ";
  }
  cout << "]" << endl;
  cout << "Front is: " << test_sortable_vector.Front() << endl;
  cout << "Back is: " << test_sortable_vector.Back() << endl;

  cout << endl << endl;

}

void testVectorStringValues() {

  cout << "Testing Vector (string values)" << endl << endl;

  bool verified_test;
  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned long> dist(1, 10000);

  
  unsigned long vector_size = dist(gen);
  // Specific constructor
  lasd::Vector<string> test_vector(vector_size);

  // Size
  if (vector_size == test_vector.Size()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Vector size is: " << test_vector.Size() << ". Test result: " << (verified_test ? "Passed" : "Error") << endl;

  // Test copy constructor
  lasd::Vector<string> copy_vector(test_vector);
  if (copy_vector == test_vector) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "2. Are vectors equal? (Copy constructor). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Fill the array with values
  for(unsigned long i = 0; i < test_vector.Size(); i++) {
    test_vector[i] = to_string(dist(gen));
  }

  // Test operators == and !=
  lasd::Vector<string> copy_vector_two(test_vector);
  if (copy_vector_two == test_vector) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "3. Are vectors equal? (Operator == ). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  lasd::Vector<string> test_vector_two(copy_vector_two.Size());
  for(unsigned long i = 0; i < test_vector_two.Size(); i++) {
    test_vector_two[i] = to_string(0);
  }

  if (copy_vector_two != test_vector_two) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "4. Are vectors not equal? (Operator !=). Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Copy assignment
  lasd::Vector<string> test_vector_three;
  test_vector_three = test_vector;
  if (test_vector == test_vector_three) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "5. Are vectors equal? (Copy assignment). Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  // Clear
  test_vector.Clear();
  try{
    cout << test_vector[5];
    verified_test = false; 
  } catch (...) {
    verified_test = true;
    cout << "6. Clearing array. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  }
  
  // Size after Clear
  if(test_vector.Size() == 0) {
    verified_test = true; 
  } else {
    verified_test = false;
  }
  cout << "7. Testing size of array after Clear. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Resize
  test_vector.Resize(20);
  if (test_vector.Size() == 20) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "8. Testing resize of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Front and Back
  string front = to_string(0);
  string back = to_string(0);

  for(unsigned long i = 0; i < 20; i++) {
    test_vector[i] = to_string(dist(gen));
    if (i == 0) { 
      front = test_vector[i]; 
    } else if (i == 19) { 
      back = test_vector[i]; 
    }
  }

  if(front == test_vector.Front()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "9. Testing Front of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  if(back == test_vector.Back()) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "10. Testing Back of array. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Test sortable array
  unsigned long sortable_vector_size = 10;
  char letter = 'z';
  lasd::SortableVector<string> test_sortable_vector(sortable_vector_size);
  cout << "11. Testing sortable array. "<< endl; 
  cout << "Sortable vector elements: [ ";

  for(unsigned long i = 0; i<test_sortable_vector.Size(); i++){
    test_sortable_vector.lasd::Vector<string>::operator[](i) = to_string(letter);
    letter--;
    cout << test_sortable_vector.lasd::Vector<string>::operator[](i) << " ";
  }
  cout << "]" << endl;
  cout << "Sorting vector elements: [ ";
  test_sortable_vector.Sort();
  for(unsigned long i = 0; i<test_sortable_vector.Size(); i++){
    cout << test_sortable_vector.lasd::Vector<string>::operator[](i) << " ";
  }
  cout << "]" << endl;
  cout << "Front is: " << test_sortable_vector.Front() << endl;
  cout << "Back is: " << test_sortable_vector.Back() << endl;

  cout << endl << endl;

}

void testList() {

  cout << "Testing List" << endl << endl;

  bool verified_test;

  // default constructor
  lasd::List<unsigned long> list;
  if(list.Size() == 0) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Testing default constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  

  // Copy constructor
  lasd::List<unsigned long> list_two;
  list_two.InsertAtFront(3);
  list_two.InsertAtFront(2);
  list_two.InsertAtFront(1);
  lasd::List<unsigned long> list_three(list_two);
  if(list_two == list_three) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "2. Testing copy constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Move constructor
  lasd::List<unsigned long> move_list(std::move(list_two));
  if ( (move_list.Size() == 3) && (list_two.Size() == 0) ) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "3. Testing move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Copy assignment
  list = list_three;
  if (list == list_three) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "4. Testing copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Move assignment
  move_list = std::move(list);
  if((move_list == list) && (move_list.Size() == list_three.Size())) {
      verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "5. Testing move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Clear()
  move_list.Clear();
  if(move_list.Size() == 0){
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "6. Clearing list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Front()
  list.Clear();
  list.InsertAtFront(3);
  list.InsertAtFront(2);
  list.InsertAtFront(1);
  if(list.Front() == 1) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "7. Front of list: " << list.Front() << ". Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Back() 
  if(list.Back() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "8. Back of list: " << list.Back() << ". Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // operator !=
  if(move_list != list) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "9. Testing operator !=. Test result: " << (verified_test ? "Passed" : " Error") << endl;
   
  // InsertAtFront()
  list.InsertAtFront(0);
  if(list.Front() == 0 && list.Size() == 4) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "10. Insert at front of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // InsertAtBack()
  list.InsertAtBack(4);
  if(list.Back() == 4 && list.Size() == 5) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "11. Insert at back of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // RemoveFromFront() 
  list.RemoveFromFront();
  if(list.Front() == 1 && list.Size() == 4) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "12. Remove from front of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // FrontNRemove() 
  list.Clear();
  list.InsertAtFront(0);
  if(list.FrontNRemove() == 0 && list.Size() == 0) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "13. Front and remove from list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // PreOrderMap() 
  list.InsertAtFront(8);
  list.InsertAtFront(6);
  list.InsertAtFront(4);
  list.InsertAtFront(2);
  list.PreOrderMap([](unsigned long& data) { data = data + 2; });
  if(list.Front() == 4 && list.Back() == 10) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "14. PreOrderMap of function on list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //List as dictionary
  lasd::List<unsigned long> dictionary_list;
  dictionary_list.Insert(1);
  dictionary_list.Insert(2);
  dictionary_list.Insert(3);

  // Insert()
  if(dictionary_list.Insert(1)) {
    verified_test = false;
  } else { 
    verified_test = true;
  }
  cout << "15. Testing dictionary list Insert. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Remove()
  if(dictionary_list.Remove(2)) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "16. Testing dictionary list Remove. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  if(dictionary_list.Remove(4)) {
    verified_test = false;
  } else { 
    verified_test = true;
  }
  cout << "17. Testing dictionary list Remove element that not exist. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Operator[]
  if(dictionary_list.operator[](0) == 1) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "18. Testing operator[] on list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  try{
    cout << dictionary_list.operator[](10);
    verified_test = false; 
  } catch (...) {
    verified_test = true;
    cout << "19. Testing operator[] out of index on list. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  }

  cout << endl << endl;
}

void testListUnsignedLongValues(){
  
  cout << "Testing List unsigned long values" << endl << endl;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned long> dist(1, 10000);

  bool verified_test;
  lasd::List<unsigned long> list;

  // Size()
  if (list.Size() == 0) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Testing list inizial size. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Front()
  try {
    cout << list.Front();
    verified_test = false;    
  } catch(...) {
    verified_test = true;
  }
  cout << "2. Front of empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Empty()
  if(list.Empty()) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "3. Empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Fill list with random values
  unsigned long front = 0;
  unsigned long back = 0;
  unsigned long element = 0;
  for(int i = 0; i < 3; i++) {
    if (i==0) {
      back = dist(gen);
      list.InsertAtFront(back);
    } else if(i==1) {
      element = dist(gen);
      list.InsertAtFront(element);
    } else {
      front = dist(gen);
      list.InsertAtFront(front);
    }
  }
  cout << "4. Fill the list. List elements: " << front << " " << element << " " << back << endl;

  //Front()
  if(list.Front() == front) { 
    verified_test = true;
  } else {
    cout << endl << list.Front() << endl ;
    verified_test = false;
  }
  cout << "5. Test the Front of the list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Back()
  if(list.Back() == back) { 
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "6. Test the Back of the list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Not empty
  if(!list.Empty()) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "7. Test not empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //RemoveFromFront()
  list.RemoveFromFront();
  if(list.Front() == element) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "8. Remove from front of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  
  lasd::List<unsigned long> other_list(list);
  if(list == other_list) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "9. Testing copy constructor of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  cout << endl << endl;
}

void testListDoubleValues(){
  
  cout << "Testing List double values" << endl << endl;

  default_random_engine gen(random_device{}());
  uniform_real_distribution<double> distx(1.0, 10000.0);

  bool verified_test;
  lasd::List<double> list;

  // Size()
  if (list.Size() == 0) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Testing list inizial size. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Front()
  try {
    cout << list.Front();
    verified_test = false;    
  } catch(...) {
    verified_test = true;
  }
  cout << "2. Front of empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Empty()
  if(list.Empty()) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "3. Empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Fill list with random values
  double front = 0.0;
  double back = 0.0;
  double element = 0.0;
  for(int i = 0; i < 3; i++) {
    if (i==0) {
      back = distx(gen);
      list.InsertAtFront(back);
    } else if(i==1) {
      element = distx(gen);
      list.InsertAtFront(element);
    } else {
      front = distx(gen);
      list.InsertAtFront(front);
    }
  }
  cout << "4. Fill the list. List elements: " << front << " " << element << " " << back << endl;

  //Front()
  if(list.Front() == front) { 
    verified_test = true;
  } else {
    cout << endl << list.Front() << endl ;
    verified_test = false;
  }
  cout << "5. Test the Front of the list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Back()
  if(list.Back() == back) { 
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "6. Test the Back of the list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Not empty
  if(!list.Empty()) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "7. Test not empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //RemoveFromFront()
  list.RemoveFromFront();
  if(list.Front() == element) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "8. Remove from front of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  
  lasd::List<double> other_list(list);
  if(list == other_list) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "9. Testing copy constructor of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  cout << endl << endl;
}

void testListStringValues(){
  
  cout << "Testing List string values" << endl << endl;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned long> dist(1, 10000);

  bool verified_test;
  lasd::List<string> list;

  // Size()
  if (list.Size() == 0) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Testing list inizial size. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Front()
  try {
    cout << list.Front();
    verified_test = false;    
  } catch(...) {
    verified_test = true;
  }
  cout << "2. Front of empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Empty()
  if(list.Empty()) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "3. Empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Fill list with random values
  string front = "0";
  string back = "0";
  string element = "0";
  for(int i = 0; i < 3; i++) {
    if (i==0) {
      back = to_string(dist(gen));
      list.InsertAtFront(back);
    } else if(i==1) {
      element = to_string(dist(gen));
      list.InsertAtFront(element);
    } else {
      front = to_string(dist(gen));
      list.InsertAtFront(front);
    }
  }
  cout << "4. Fill the list. List elements: " << front << " " << element << " " << back << endl;

  //Front()
  if(list.Front() == front) { 
    verified_test = true;
  } else {
    cout << endl << list.Front() << endl ;
    verified_test = false;
  }
  cout << "5. Test the Front of the list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Back()
  if(list.Back() == back) { 
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "6. Test the Back of the list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Not empty
  if(!list.Empty()) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "7. Test not empty list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //RemoveFromFront()
  list.RemoveFromFront();
  if(list.Front() == element) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "8. Remove from front of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  
  lasd::List<string> other_list(list);
  if(list == other_list) {
    verified_test = true;
  } else { 
    verified_test = false;
  }
  cout << "9. Testing copy constructor of list. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  cout << endl << endl;
}

void testStack(){

  lasd::StackVec<unsigned long> stack_vec_ulong1;
  lasd::StackVec<unsigned long> stack_vec_ulong2;
  lasd::StackLst<unsigned long> stack_lst_ulong1;
  lasd::StackLst<unsigned long> stack_lst_ulong2;

  lasd::StackVec<double> stack_vec_double1;
  lasd::StackVec<double> stack_vec_double2;
  lasd::StackLst<double> stack_lst_double1;
  lasd::StackLst<double> stack_lst_double2;

  lasd::StackVec<string> stack_vec_string1;
  lasd::StackVec<string> stack_vec_string2;
  lasd::StackLst<string> stack_lst_string1;
  lasd::StackLst<string> stack_lst_string2;

  cout << endl << endl << "Test on StackVec<unsigned long> : " << endl;
  testStackUnsignedLongValues(stack_vec_ulong1, stack_vec_ulong2);
  cout << endl << endl << "Test on StackLst<unsigned long> : " << endl;
  testStackUnsignedLongValues(stack_lst_ulong1, stack_lst_ulong2);

  
  cout << endl << endl << "Test on StackVec<double> : " << endl;
  testStackDoubleValues(stack_vec_double1, stack_vec_double2);
  cout << endl << endl << "Test on StackLst<double> : " << endl;
  testStackDoubleValues(stack_lst_double1, stack_lst_double2);

  cout << endl << endl << "Test on StackVec<string> : " << endl;
  testStackStringValues(stack_vec_string1, stack_vec_string2);
  cout << endl << endl << "Test on StackLst<string> : " << endl;
  testStackStringValues(stack_lst_string1, stack_lst_string2);

}

template <typename Stack>
void testStackUnsignedLongValues (Stack &stack, Stack &other_stack) {
  
  cout << "Testing Stack unsigned long values" << endl << endl;
  bool verified_test;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned long> dist(1, 10000);

  // Empty()
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "1. Testing Empty stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size()
  if (stack.Size() == 0) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "2. Testing size of empty stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top of stack
  stack.Push(0);
  if (stack.Top() == 0) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "3. Testing top of stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size after push
  if (stack.Size() == 1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "4. Testing size after Push. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top after Push
  stack.Push(1);
  if (stack.Top() == 1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "5. Testing top after Push. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size
  stack.Push(2);
  stack.Push(3);
  if (stack.Size() == 4) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "6. Testing size of stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Pop
  stack.Pop();
  if (stack.Top() == 2) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "7. Testing Pop on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size after Pop
  if (stack.Size() == 3) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "8. Testing size of stack after Pop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Empty stack after Pop
  stack.Pop();
  stack.Pop();
  stack.Pop();
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "9. Testing empty stack after Pop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // TopNPop
  stack.Push(0);
  stack.Push(1);
  if (stack.TopNPop() == 1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "10. Testing TopNPop on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top of stack after TopNPop
  if (stack.Top() == 0) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "11. Testing top of stack after TopNPop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Clearing stack
  stack.Clear();
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "12. Testing Clear on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Operator ==
  stack.Push(5);
  other_stack.Push(5);
  if (stack == other_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "13. Testing operator ==. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Operator !=
  stack.Push(6);
  other_stack.Push(7);
  if (stack != other_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "14. Testing operator !=. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Fill the stack with random values
  stack.Clear();
  unsigned long limit = dist(gen);
  for (unsigned long i = 0; i < limit; i++) {
    stack.Push(dist(gen));
  }

  if (stack.Size() == limit) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "15. Fill the stack with random values. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // copy constructor
  Stack copy_stack(stack);
  if (stack == copy_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "16. Testing copy constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // move constructor
  other_stack.Clear();
  other_stack.Push(0);
  other_stack.Push(1);
  other_stack.Push(2);
  Stack move_stack(std::move(other_stack));
  if (move_stack.Top() == 2) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "17. Testing move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // stack after  move constructor
  if (other_stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "18. Testing empty stack after move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // copy assigment
  other_stack = move_stack;
  if (other_stack == move_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "19. Testing stack copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // move assignment
  Stack other_move_stack = move_stack; 
  move_stack.Clear();
  move_stack = std::move(other_stack);
  if (move_stack == other_move_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "20. Testing stack move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
}

template <typename Stack>
void testStackDoubleValues (Stack &stack, Stack &other_stack) {

  cout << "Testing Stack double values" << endl << endl;
  bool verified_test;

  default_random_engine gen(random_device{}());
  uniform_real_distribution<double> dist(1.0, 10000.0);

  // Empty()
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "1. Testing Empty stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size()
  if (stack.Size() == 0) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "2. Testing size of empty stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top of stack
  stack.Push(0.1);
  if (stack.Top() == 0.1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "3. Testing top of stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size after push
  if (stack.Size() == 1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "4. Testing size after Push. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top after Push
  stack.Push(1.1);
  if (stack.Top() == 1.1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "5. Testing top after Push. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size
  stack.Push(2.1);
  stack.Push(3.1);
  if (stack.Size() == 4) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "6. Testing size of stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Pop
  stack.Pop();
  if (stack.Top() == 2.1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "7. Testing Pop on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size after Pop
  if (stack.Size() == 3) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "8. Testing size of stack after Pop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Empty stack after Pop
  stack.Pop();
  stack.Pop();
  stack.Pop();
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "9. Testing empty stack after Pop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // TopNPop
  stack.Push(0.1);
  stack.Push(1.1);
  if (stack.TopNPop() == 1.1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "10. Testing TopNPop on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top of stack after TopNPop
  if (stack.Top() == 0.1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "11. Testing top of stack after TopNPop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Clearing stack
  stack.Clear();
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "12. Testing Clear on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Operator ==
  stack.Push(5.1);
  other_stack.Push(5.1);
  if (stack == other_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "13. Testing operator ==. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Operator !=
  stack.Push(6.1);
  other_stack.Push(7.1);
  if (stack != other_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "14. Testing operator !=. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Fill the stack with random values
  stack.Clear();
  unsigned long limit = 100;
  for (unsigned long i = 0; i < limit; i++) {
    stack.Push(dist(gen));
  }

  if (stack.Size() == limit) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "15. Fill the stack with random values. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // copy constructor
  Stack copy_stack(stack);
  if (stack == copy_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "16. Testing copy constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // move constructor
  other_stack.Clear();
  other_stack.Push(0.1);
  other_stack.Push(1.1);
  other_stack.Push(2.1);
  Stack move_stack(std::move(other_stack));
  if (move_stack.Top() == 2.1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "17. Testing move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // stack after  move constructor
  if (other_stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "18. Testing empty stack after move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // copy assigment
  other_stack = move_stack;
  if (other_stack == move_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "19. Testing stack copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // move assignment
  Stack other_move_stack = move_stack; 
  move_stack.Clear();
  move_stack = std::move(other_stack);
  if (move_stack == other_move_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "20. Testing stack move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
}

template <typename Stack>
void testStackStringValues (Stack &stack, Stack &other_stack) {

  cout << "Testing Stack string values" << endl << endl;
  bool verified_test;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned long> dist(1, 10000);

  // Empty()
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "1. Testing Empty stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size()
  if (stack.Size() == 0) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "2. Testing size of empty stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top of stack
  stack.Push("zero");
  if (stack.Top() == "zero") {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "3. Testing top of stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size after push
  if (stack.Size() == 1) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "4. Testing size after Push. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top after Push
  stack.Push("uno");
  if (stack.Top() == "uno") {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "5. Testing top after Push. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size
  stack.Push("due");
  stack.Push("tre");
  if (stack.Size() == 4) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "6. Testing size of stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Pop
  stack.Pop();
  if (stack.Top() == "due") {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "7. Testing Pop on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Size after Pop
  if (stack.Size() == 3) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "8. Testing size of stack after Pop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Empty stack after Pop
  stack.Pop();
  stack.Pop();
  stack.Pop();
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "9. Testing empty stack after Pop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // TopNPop
  stack.Push("zero");
  stack.Push("uno");
  if (stack.TopNPop() == "uno") {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "10. Testing TopNPop on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Top of stack after TopNPop
  if (stack.Top() == "zero") {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "11. Testing top of stack after TopNPop. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Clearing stack
  stack.Clear();
  if (stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "12. Testing Clear on stack. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Operator ==
  stack.Push("cinque");
  other_stack.Push("cinque");
  if (stack == other_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "13. Testing operator ==. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Operator !=
  stack.Push("sei");
  other_stack.Push("sette");
  if (stack != other_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "14. Testing operator !=. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Fill the stack with random values
  stack.Clear();
  unsigned long limit = 100;
  for (unsigned long i = 0; i < limit; i++) {
    stack.Push(to_string(dist(gen)));
  }

  if (stack.Size() == limit) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "15. Fill the stack with random values. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // copy constructor
  Stack copy_stack(stack);
  if (stack == copy_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "16. Testing copy constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // move constructor
  other_stack.Clear();
  other_stack.Push("zero");
  other_stack.Push("uno");
  other_stack.Push("due");
  Stack move_stack(std::move(other_stack));
  if (move_stack.Top() == "due") {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "17. Testing move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // stack after  move constructor
  if (other_stack.Empty()) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "18. Testing empty stack after move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // copy assigment
  other_stack = move_stack;
  if (other_stack == move_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "19. Testing stack copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // move assignment
  Stack other_move_stack = move_stack; 
  move_stack.Clear();
  move_stack = std::move(other_stack);
  if (move_stack == other_move_stack) {
    verified_test = true;
  } else {
    verified_test = false;
  }
  cout << "20. Testing stack move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
}

void testQueue(){

  lasd::QueueVec<unsigned long> queue_vec_ulong;
  lasd::QueueLst<unsigned long> queue_lst_ulong;

  lasd::QueueVec<double> queue_vec_double;
  lasd::QueueLst<double> queue_lst_double;

  lasd::QueueVec<string> queue_vec_string;
  lasd::QueueLst<string> queue_lst_string;

  cout << endl << endl << "Test on QueueVec<unsigned long> : " << endl;
  testQueueUnsignedLongValues(queue_vec_ulong);
  cout << endl << endl << "Test on QueueLst<unsigned long> : " << endl;
  testQueueUnsignedLongValues(queue_lst_ulong);

  cout << endl << endl << "Test on QueueVec<double> : " << endl;
  testQueueDoubleValues(queue_vec_double);
  cout << endl << endl << "Test on QueueLst<double> : " << endl;
  testQueueDoubleValues(queue_lst_double);

  cout << endl << endl << "Test on QueueVec<string> : " << endl;
  testQueueStringValues(queue_vec_string);
  cout << endl << endl << "Test on QueueLst<string> : " << endl;
  testQueueStringValues(queue_lst_string);

}

template <typename Queue>
void testQueueUnsignedLongValues(Queue& queue){

  cout << "Testing Queue unsigned long values" << endl << endl;
  bool verified_test;

  queue.Enqueue(5);
  queue.Enqueue(10);
  queue.Enqueue(15);
  queue.Enqueue(20);
  queue.Enqueue(25);

  //Size()
  if(queue.Size() == 5) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Testing queue size. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head()
  if(queue.Head() == 5) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "2. Testing queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size() after Dequeue
  queue.Dequeue();
  if(queue.Size() == 4) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "3. Testing size of queue after dequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head() after Dequeue
  if(queue.Head() == 10) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "4. Testing head of queue after dequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //HeadNDequeue()
  if(queue.HeadNDequeue() == 10) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "5. Testing HeadNDqueue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size() after HeadNDequeue
  if(queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "6. Testing size of queue after HeadNDequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head() after HeadNDequeue
  if(queue.Head() == 15) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "7. Testing head of queue after HeadNDequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy constructor
  Queue copy_queue(queue);
  if(copy_queue.Size() == 3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "8. Testing copy constructor of queue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after copy constructor
  if(copy_queue.Head() == 15){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "9. Testing copy queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Testing the move constructor
  Queue move_queue(std::move(copy_queue));
  if(move_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "10. Testing move constructor queue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after move constructor
  if(move_queue.Head() == 15){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "11. Testing move queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy queue after move constructor
  if(copy_queue.Empty()){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "12. Testing copy queue after move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy assignment 
  Queue other_queue;
  other_queue.Enqueue(0);
  other_queue = move_queue;
  if(other_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "13. Testing copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after Copy assignment
  if(other_queue.Head() == 15) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "14. Testing head of queue after copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Move assignment 
  Queue other_move_queue;
  other_move_queue.Enqueue(0);
  other_move_queue = std::move(other_queue);

  if(other_move_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "15. Testing move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after move assignment
  if(other_move_queue.Head() == 15){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "16. Testing head of queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size of queue after move assignment
  if(other_move_queue.Size() == 3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "17. Testing size of queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head of other queue after move assignment
  if(other_queue.Head() == 0){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "18. Testing head of other queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Operators == and !=
  Queue equal_queue(other_move_queue);
  if(other_move_queue == equal_queue){
    verified_test = true;
  } else {
    verified_test = false; 
  }
  cout << "19. Testing operator ==. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  if(other_move_queue != other_queue){
    verified_test = true;
  } else {
    verified_test = false; 
  }
  cout << "20. Testing operator !=. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  //Clear and Empty
  equal_queue.Clear();
  if(equal_queue.Empty()){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "21. Testing Empty queue after Clear. Test result: " << (verified_test ? "Passed" : " Error") << endl;

}

template <typename Queue>
void testQueueDoubleValues(Queue& queue){

  cout << "Testing Queue double values" << endl << endl;
  bool verified_test;

  queue.Enqueue(5.1);
  queue.Enqueue(10.2);
  queue.Enqueue(15.3);
  queue.Enqueue(20.4);
  queue.Enqueue(25.5);

  //Size()
  if(queue.Size() == 5) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Testing queue size. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head()
  if(queue.Head() == 5.1) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "2. Testing queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size() after Dequeue
  queue.Dequeue();
  if(queue.Size() == 4) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "3. Testing size of queue after dequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head() after Dequeue
  if(queue.Head() == 10.2) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "4. Testing head of queue after dequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //HeadNDequeue()
  if(queue.HeadNDequeue() == 10.2) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "5. Testing HeadNDqueue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size() after HeadNDequeue
  if(queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "6. Testing size of queue after HeadNDequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head() after HeadNDequeue
  if(queue.Head() == 15.3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "7. Testing head of queue after HeadNDequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy constructor
  Queue copy_queue(queue);
  if(copy_queue.Size() == 3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "8. Testing copy constructor of queue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after copy constructor
  if(copy_queue.Head() == 15.3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "9. Testing copy queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Testing the move constructor
  Queue move_queue(std::move(copy_queue));
  if(move_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "10. Testing move constructor queue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after move constructor
  if(move_queue.Head() == 15.3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "11. Testing move queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy queue after move constructor
  if(copy_queue.Empty()){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "12. Testing copy queue after move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy assignment 
  Queue other_queue;
  other_queue.Enqueue(0.9);
  other_queue = move_queue;
  if(other_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "13. Testing copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after Copy assignment
  if(other_queue.Head() == 15.3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "14. Testing head of queue after copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Move assignment 
  Queue other_move_queue;
  other_move_queue.Enqueue(0.9);
  other_move_queue = std::move(other_queue);

  if(other_move_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "15. Testing move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after move assignment
  if(other_move_queue.Head() == 15.3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "16. Testing head of queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size of queue after move assignment
  if(other_move_queue.Size() == 3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "17. Testing size of queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head of other queue after move assignment
  if(other_queue.Head() == 0.9){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "18. Testing head of other queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Operators == and !=
  Queue equal_queue(other_move_queue);
  if(other_move_queue == equal_queue){
    verified_test = true;
  } else {
    verified_test = false; 
  }
  cout << "19. Testing operator ==. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  if(other_move_queue != other_queue){
    verified_test = true;
  } else {
    verified_test = false; 
  }
  cout << "20. Testing operator !=. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  //Clear and Empty
  equal_queue.Clear();
  if(equal_queue.Empty()){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "21. Testing Empty queue after Clear. Test result: " << (verified_test ? "Passed" : " Error") << endl;

}

template <typename Queue>
void testQueueStringValues(Queue& queue){

  cout << "Testing Queue string values" << endl << endl;
  bool verified_test;

  queue.Enqueue("cinque");
  queue.Enqueue("dieci");
  queue.Enqueue("quindici");
  queue.Enqueue("venti");
  queue.Enqueue("venticinque");

  //Size()
  if(queue.Size() == 5) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "1. Testing queue size. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head()
  if(queue.Head() == "cinque") {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "2. Testing queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size() after Dequeue
  queue.Dequeue();
  if(queue.Size() == 4) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "3. Testing size of queue after dequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head() after Dequeue
  if(queue.Head() == "dieci") {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "4. Testing head of queue after dequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //HeadNDequeue()
  if(queue.HeadNDequeue() == "dieci") {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "5. Testing HeadNDqueue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size() after HeadNDequeue
  if(queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "6. Testing size of queue after HeadNDequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head() after HeadNDequeue
  if(queue.Head() == "quindici") {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "7. Testing head of queue after HeadNDequeue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy constructor
  Queue copy_queue(queue);
  if(copy_queue.Size() == 3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "8. Testing copy constructor of queue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after copy constructor
  if(copy_queue.Head() == "quindici"){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "9. Testing copy queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  // Testing the move constructor
  Queue move_queue(std::move(copy_queue));
  if(move_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "10. Testing move constructor queue. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after move constructor
  if(move_queue.Head() == "quindici"){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "11. Testing move queue head. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy queue after move constructor
  if(copy_queue.Empty()){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "12. Testing copy queue after move constructor. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Copy assignment 
  Queue other_queue;
  other_queue.Enqueue("zero");
  other_queue = move_queue;
  if(other_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "13. Testing copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after Copy assignment
  if(other_queue.Head() == "quindici") {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "14. Testing head of queue after copy assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Move assignment 
  Queue other_move_queue;
  other_move_queue.Enqueue("zero");
  other_move_queue = std::move(other_queue);

  if(other_move_queue.Size() == 3) {
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "15. Testing move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head after move assignment
  if(other_move_queue.Head() == "quindici"){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "16. Testing head of queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Size of queue after move assignment
  if(other_move_queue.Size() == 3){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "17. Testing size of queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Head of other queue after move assignment
  if(other_queue.Head() == "zero"){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "18. Testing head of other queue after move assignment. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  //Operators == and !=
  Queue equal_queue(other_move_queue);
  if(other_move_queue == equal_queue){
    verified_test = true;
  } else {
    verified_test = false; 
  }
  cout << "19. Testing operator ==. Test result: " << (verified_test ? "Passed" : " Error") << endl;

  if(other_move_queue != other_queue){
    verified_test = true;
  } else {
    verified_test = false; 
  }
  cout << "20. Testing operator !=. Test result: " << (verified_test ? "Passed" : " Error") << endl;
  
  //Clear and Empty
  equal_queue.Clear();
  if(equal_queue.Empty()){
    verified_test = true;
  } else { 
    verified_test = false; 
  }
  cout << "21. Testing Empty queue after Clear. Test result: " << (verified_test ? "Passed" : " Error") << endl;

}

/* ************************************************************************** */
/* ************************************************************************** */

  //inizio test ex.2

  void myTestExercise2()
  {
    cout << "***** My test Exercise 2 *****" << endl << endl;

    unsigned int struttura;
    unsigned int tipo_struttura;

    do
    {
      struttura = scegliStruttura();
      if (struttura == 0) { break; }

      tipo_struttura = scegliTipoStruttura();
      if (tipo_struttura == 0) { continue; }
        
      if (struttura == BTVEC) // vogliamo testare un binary tree vec 
      {
        if (tipo_struttura == INT)
        {
          lasd::List<int> list;
          riempiLista(list);
          lasd::BinaryTreeVec<int> binary_tree_vec(list);
          testBinaryTree(binary_tree_vec);
        }
        else if (tipo_struttura == DOUBLE)
        {
          lasd::List<double> list;
          riempiLista(list);
          lasd::BinaryTreeVec<double> binary_tree_vec(list);
          testBinaryTree(binary_tree_vec);
        }
        else if (tipo_struttura == STRING)
        {
          lasd::List<std::string> list;
          riempiLista(list);
          lasd::BinaryTreeVec<std::string> binary_tree_vec(list);
          testBinaryTree(binary_tree_vec);
        }
      }
      else if (struttura == BTLNK) // vogliamo testare un binary tree lnk 
      {
        if (tipo_struttura == INT)
        {
          lasd::List<int> list;
          riempiLista(list);
          lasd::BinaryTreeLnk<int> binary_tree_lnk(list);
          testBinaryTree(binary_tree_lnk);
        }
        else if (tipo_struttura == DOUBLE)
        {
          lasd::List<double> list;
          riempiLista(list);
          lasd::BinaryTreeLnk<double> binary_tree_lnk(list);
          testBinaryTree(binary_tree_lnk);
        }
        else if (tipo_struttura == STRING)
        {
          lasd::List<std::string> list;
          riempiLista(list);
          lasd::BinaryTreeLnk<std::string> binary_tree_lnk(list);
          testBinaryTree(binary_tree_lnk);
        }
      }
      else if (struttura == BSTT) // vogliamo testare un bst
      {
        if (tipo_struttura == INT)
        {
          lasd::List<int> list;
          riempiLista(list);
          lasd::BST<int> bst(list);
          testBST(bst);
        }
        else if (tipo_struttura == DOUBLE)
        {
          lasd::List<double> list;
          riempiLista(list);
          lasd::BST<double> bst(list);
          testBST(bst);
        }
        else if (tipo_struttura == STRING)
        {
          lasd::List<std::string> list;
          riempiLista(list);
          lasd::BST<std::string> bst(list);
          testBST(bst);
        }
      }

    } while (true);
  }

  ////////////////////////////////////////////////////////////////

  unsigned int scegliStruttura()
  {
    unsigned int scelta;
    cout << "\nScegli quale struttura dati vuoi utilizzare:\n";
    cout << "1. BinaryTreeVec\n";
    cout << "2. BinaryTreeLnk\n";
    cout << "3. BST\n";
    cout << "0. Esci\n\n";

    do
    {
      try
      {
        getValue(scelta);
        if (scelta == 0 || scelta == 1 || scelta == 2 || scelta == 3)
        {
          break;
        }
        else
        {
          throw invalid_argument("");
        }
      }
      catch (const logic_error &errore)
      {
        cout << "";
        //cout << "Errore: " << errore.what() << "\n";
      }
    } 
    while (true);

    return scelta;
  }

  ////////////////////////////////////////////////////////////////

  unsigned int scegliTipoStruttura()
  {
    unsigned int scelta;
    cout << "\nScegli il tipo dei dati della struttura: \n";
    cout << "1. int\n";
    cout << "2. double\n";
    cout << "3. string\n";
    cout << "0. Torna indietro\n\n";

    do
    {
      try
      {
        getValue(scelta);
        if (scelta == 0 || scelta == 1 || scelta == 2 || scelta == 3)
        {
          break;
        }
        else
        {
          throw invalid_argument("");
        }
      }
      catch (const logic_error &errore)
      {
        cout << "Scelta non valida! Riprova.\n";
      }

    } while (true);

    return scelta;
  }

  ////////////////////////////////////////////////////////////////
  
  
  void riempiLista(lasd::List<int> & list)
  {
    for (unsigned long i = 0; i < DIMENSIONE; i++)
    {
      list.Insert(generaInt());
    }
  }

  void riempiLista(lasd::List<double> & list)
  {
    for (unsigned long i = 0; i < DIMENSIONE; i++)
    {
      list.Insert(generaDouble());
    }
  }

  void riempiLista(lasd::List<std::string> & list)
  {
    for (unsigned long i = 0; i < DIMENSIONE; i++)
    {
      list.Insert(generaString());
    }
  }

  ////////////////////////////////////////////////////////////////

  int generaInt()
  {
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> dist(0, 100);
    return dist(gen);
  }

  double generaDouble()
  {
    default_random_engine gen(random_device{}());
    uniform_real_distribution<double> dist(0, 50);
    double num = dist(gen);
    num = std::round(num * 100) / 100;
    return num;
  }

  std::string generaString()
  {
    const std::string CARATTERI = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 gen(random_device());
    uniform_int_distribution<> dist(0, CARATTERI.size()-1);

    std::string stringa;
    for (size_t i = 0; i < 3; i++)
    {
      stringa += CARATTERI[dist(gen)];
    }

    return stringa;
  }

  ////////////////////////////////////////////////////////////////

  void getValue(int &val)
  {
    std::string input;
    getline(std::cin, input);
    val = stoi(input);
  }

  void getValue(unsigned int &val)
  {
    std::string input;
    getline(std::cin, input);
    val = stoul(input);
  }

  void getValue(double &val)
  {
    std::string input;
    getline(std::cin, input);
    val = std::stod(input);
  }

  void getValue(std::string &val)
  {
    getline(std::cin, val);
  }

  ////////////////////////////////////////////////////////////////

  template <typename Data>
  void testBinaryTree(lasd::MutableBinaryTree<Data> &tree)
  {
    unsigned int scelta;

    do
    {
      cout << "\n\n***** Binary Tree *****\n";
      cout << "\nScegli l'operazione da eseguire:\n";
      cout << "1. Visualizza albero generato\n";
      cout << "2. Clear\n";
      cout << "3. Exists di un valore\n";
      cout << "4. Test iteratori sull'albero\n";
      cout << "5. Map (PreOrder)\n";
      cout << "0. Esci\n\n";

      try
      {
        getValue(scelta);

        if (scelta == 0)
        {
          break;
        }
        else if (scelta == 1)
        {
          cout << "\nEcco l'albero binario generato...\n\n";
          tree.ViewTree();
        }
        else if (scelta == 2)
        {
          tree.Clear();
          cout << "\nClear applicata con successo all'albero\n\n";
        }
        else if (scelta == 3)
        {

          Data val;
          cout << "\nInserisci il valore da ricercare nell'albero: \n";
          getValue(val);

          if (tree.Exists(val))
          {
            cout << "\nIl valore ricercato e' presente nell'albero\n\n";
          }
          else
          {
            cout << "\nIl valore ricercato non e' presente nell'albero\n\n";
          }
        }
        else if (scelta == 4)
        {
          unsigned int sceltait;

          cout << "\n\nSeleziona l'iteratore da testare:\n";
          cout << "1. PreOrderIterator\n";
          cout << "2. PostOrder Iterator\n";
          cout << "3. InOrder Iterator\n";
          cout << "4. Breadth Iterator\n";
          cout << "0. Esci\n\n";

          getValue(sceltait);

          if (sceltait == 1)
          {
            lasd::BTPreOrderMutableIterator<Data> it(tree);
            testPreOrderIterator(it);
          }
          else if (sceltait == 2)
          {
            lasd::BTPostOrderMutableIterator<Data> it(tree);
            testPostOrderIterator(it);
          }
          else if (sceltait == 3)
          {
            lasd::BTInOrderMutableIterator<Data> it(tree);
            testInOrderIterator(it);
          }
          else if (sceltait == 4)
          {
            lasd::BTBreadthMutableIterator<Data> it(tree);
            testBreadthIterator(it);
          }
          else
          {
            throw invalid_argument("");
          }
        }
        else if (scelta == 5)
        {
         
          tree.PreOrderMap(&Increment<Data>);
          cout << "\nMap applicata con successo all'albero\n\n";
        }
        else
        {
          throw invalid_argument("");
        }
      }
      catch (const std::length_error &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::out_of_range &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::logic_error &errore)
      {
        cout << "\nErrore. Riprova!\n";
      }

    } 
    while (true);
  }

  ////////////////////////////////////////////////////////////////

  template <typename Data>
  void testBST(lasd::BST<Data> &tree)
  {
    unsigned int scelta;

    do
    {
      cout << "\n\n***** BST *****\n";
      cout << "\nScegli l'operazione da eseguire:\n";
      cout << "1. Visualizza albero generato\n";
      cout << "2. Clear\n";
      cout << "3. Exists di un valore\n";
      cout << "4. Test iteratori sull'albero\n";
      cout << "5. Insert valore\n";
      cout << "6. Remove valore\n";
      cout << "7. MinNRemove valore\n";
      cout << "8. MaxNRemove valore\n";
      cout << "9. Predecessor valore\n";
      cout << "10. PredecessorNRemove valore\n";
      cout << "11. Successor valore\n";
      cout << "12. SuccessorNRemove valore\n";
      cout << "0. Esci\n\n";

      try
      {
        getValue(scelta);

        if (scelta == 0)
        {
          break;
        }
        else if (scelta == 1)
        {
          cout << "\nEcco l'albero binario di ricerca generato...\n\n";
          tree.ViewTree();
        }
        else if (scelta == 2)
        {
          tree.Clear();
          cout << "\nClear applicata con successo all'albero\n\n";
        }
        else if (scelta == 3)
        {

          Data val;
          cout << "\nInserisci il valore da ricercare nell'albero: \n";
          getValue(val);

          if (tree.Exists(val))
          {
            cout << "\nIl valore ricercato e' presente nell'albero\n\n";
          }
          else
          {
            cout << "\nIl valore ricercato non e' presente nell'albero\n\n";
          }
        }
        else if (scelta == 4)
        {
          unsigned int sceltait;

          cout << "\n\nSeleziona l'iteratore da testare:\n";
          cout << "1. PreOrderIterator\n";
          cout << "2. PostOrder Iterator\n";
          cout << "3. InOrder Iterator\n";
          cout << "4. Breadth Iterator\n";
          cout << "0. Esci\n\n";

          getValue(sceltait);

          if (sceltait == 1)
          {
            lasd::BTPreOrderMutableIterator<Data> it(tree);
            testPreOrderIterator(it);
          }
          else if (sceltait == 2)
          {
            lasd::BTPostOrderMutableIterator<Data> it(tree);
            testPostOrderIterator(it);
          }
          else if (sceltait == 3)
          {
            lasd::BTInOrderMutableIterator<Data> it(tree);
            testInOrderIterator(it);
          }
          else if (sceltait == 4)
          {
            lasd::BTBreadthMutableIterator<Data> it(tree);
            testBreadthIterator(it);
          }
          else
          {
            throw invalid_argument("");
          }
        }
        else if (scelta == 5)
        {
          Data val;
          cout << "\nInserisci il valore da inserire:\n";
          getValue(val);

          if (tree.Insert(val))
          {
            cout << "\nValore inserito correttamente!\n";
          }
          else
          {
            cout << "\nErrore. Il valore e' gia' presente!\n";
          }
        }
        else if (scelta == 6)
        {
          Data val;
          cout << "\nInserisci il valore da rimuovere:\n";
          getValue(val);

          if (tree.Remove(val))
          {
            cout << "\nValore rimosso correttamente!\n";
          }
          else
          {
            cout << "\nErrore nella rimozione del valore! Il valore non esiste.\n";
          }
        }
        else if (scelta == 7)
        {
          Data min = tree.MinNRemove();
          cout << "\nMin: " << min << "\n";
          cout << "\nValore Min rimosso correttamente!\n";
        }
        else if (scelta == 8)
        {
          Data max = tree.MaxNRemove();
          cout << "\nMax: " << max << "\n";
          cout << "\nValore Max rimosso correttamente!\n";
        }
        else if (scelta == 9)
        {
          Data val;
          cout << "\nInserisci il valore di cui vuoi il Predecessor:\n";
          getValue(val);
          Data pred = tree.Predecessor(val);
          cout << "\nPredecessor del valore " << val << " : " << pred << "\n";
        }
        else if (scelta == 10)
        {
          Data val;
          cout << "\nInserisci il valore di cui vuoi rimuovere il Predecessor:\n";
          getValue(val);
          Data pred = tree.PredecessorNRemove(val);
          cout << "\nPredecessor del valore " << val << " : " << pred << "\n";
          cout << "\nPredecessor correttamente rimosso dal BST!\n";
        }
        else if (scelta == 11)
        {
          Data val;
          cout << "\nInserisci il valore di cui vuoi il Successor:\n";
          getValue(val);
          Data succ = tree.Successor(val);
          cout << "\nSuccessor del valore " << val << " : " << succ << "\n";
        }
        else if (scelta == 12)
        {
          Data val;
          cout << "\nInserisci il valore di cui vuoi rimuovere il Successor:\n";
          getValue(val);
          Data succ = tree.SuccessorNRemove(val);
          cout << "\nSuccessor del valore " << val << " : " << succ << "\n";
          cout << "\nSuccessor correttamente rimosso dal BST!\n";
        }
        else
        {
          throw invalid_argument("");
        }
      }
      catch (const std::length_error &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::out_of_range &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::logic_error &errore)
      {
        cout << "\nErrore. Riprova!\n";
      }

    } 
    while (true);

  }

  ////////////////////////////////////////////////////////////////

  template <typename Data>
  void testPreOrderIterator(lasd::BTPreOrderMutableIterator<Data> & it)
  {
    unsigned int scelta;

    do
    {
      cout << "\n\n***** PREORDER ITERATOR *****\n";
      cout << "\nScegli l'operazione da eseguire:\n";
      cout << "1. Visualizza elemento corrente (*)\n";
      cout << "2. Incrementa iteratore (++)\n";
      cout << "3. Reset iteratore\n";
      cout << "0. Esci\n\n";

      try
      {
        getValue(scelta);

        if (scelta == 0)
        {
          break;
        }
        else if (scelta == 1)
        {
          Data curr = *it;
          cout << "\nL' elemento corrente e': " << curr << "\n";
        }
        else if (scelta == 2)
        {
          ++it;
          cout << "\nIteratore incrementato correttamente!\n";
        }
        else if (scelta == 3)
        {
          it.Reset();
          cout << "\nIteratore resettato correttamente!\n";
        }
        else
        {
          throw std::invalid_argument("");
        }
      }
      catch (const std::length_error &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::out_of_range &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::logic_error &errore)
      {
        cout << "\nErrore. Riprova!\n";
      }
    } 
    while (true);
  }

  ////////////////////////////////////////////////////////////////

  template <typename Data>
  void testPostOrderIterator(lasd::BTPostOrderMutableIterator<Data> & it)
  {
    unsigned int scelta;

    do
    {
      cout << "\n\n***** POSTORDER ITERATOR *****\n";
      cout << "\nScegli l'operazione da eseguire:\n";
      cout << "1. Visualizza elemento corrente (*)\n";
      cout << "2. Incrementa iteratore (++)\n";
      cout << "3. Reset iteratore\n";
      cout << "0. Esci\n\n";

      try
      {
        getValue(scelta);

        if (scelta == 0)
        {
          break;
        }
        else if (scelta == 1)
        {
          Data curr = *it;
          cout << "\nL' elemento corrente e': " << curr << "\n";
        }
        else if (scelta == 2)
        {
          ++it;
          cout << "\nIteratore incrementato correttamente!\n";
        }
        else if (scelta == 3)
        {
          it.Reset();
          cout << "\nIteratore resettato correttamente!\n";
        }
        else
        {
          throw std::invalid_argument("");
        }
      }
      catch (const std::length_error &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::out_of_range &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::logic_error &errore)
      {
        cout << "\nErrore. Riprova!\n";
      }
    } 
    while (true);
  }

  ////////////////////////////////////////////////////////////////

  template <typename Data>
  void testInOrderIterator(lasd::BTInOrderMutableIterator<Data> & it)
  {
    unsigned int scelta;

    do
    {
      cout << "\n\n***** INORDER ITERATOR *****\n";
      cout << "\nScegli l'operazione da eseguire:\n";
      cout << "1. Visualizza elemento corrente (*)\n";
      cout << "2. Incrementa iteratore (++)\n";
      cout << "3. Reset iteratore\n";
      cout << "0. Esci\n\n";

      try
      {
        getValue(scelta);

        if (scelta == 0)
        {
          break;
        }
        else if (scelta == 1)
        {
          Data curr = *it;
          cout << "\nL' elemento corrente e': " << curr << "\n";
        }
        else if (scelta == 2)
        {
          ++it;
          cout << "\nIteratore incrementato correttamente!\n";
        }
        else if (scelta == 3)
        {
          it.Reset();
          cout << "\nIteratore resettato correttamente!\n";
        }
        else
        {
          throw std::invalid_argument("");
        }
      }
      catch (const std::length_error &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::out_of_range &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::logic_error &errore)
      {
        cout << "\nErrore. Riprova!\n";
      }
    } 
    while (true);
  }

  ////////////////////////////////////////////////////////////////

  template <typename Data>
  void testBreadthIterator(lasd::BTBreadthMutableIterator<Data> & it)
  {
    unsigned int scelta;

    do
    {
      cout << "\n\n***** BREADTH ITERATOR *****\n";
      cout << "\nScegli l'operazione da eseguire:\n";
      cout << "1. Visualizza elemento corrente (*)\n";
      cout << "2. Incrementa iteratore (++)\n";
      cout << "3. Reset iteratore\n";
      cout << "0. Esci\n\n";

      try
      {
        getValue(scelta);

        if (scelta == 0)
        {
          break;
        }
        else if (scelta == 1)
        {
          Data curr = *it;
          cout << "\nL' elemento corrente e': " << curr << "\n";
        }
        else if (scelta == 2)
        {
          ++it;
          cout << "\nIteratore incrementato correttamente!\n";
        }
        else if (scelta == 3)
        {
          it.Reset();
          cout << "\nIteratore resettato correttamente!\n";
        }
        else
        {
          throw std::invalid_argument("");
        }
      }
      catch (const std::length_error &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::out_of_range &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::logic_error &errore)
      {
        cout << "\nErrore. Riprova!\n";
      }
    } 
    while (true);
  }

  /* ************************************************************************** */
  /* ************************************************************************** */

  //inizio test ex.3

  void myTestExercise3()
  {
    cout << "***** My test Exercise 3 *****" << endl << endl;

    unsigned int struttura;
    unsigned int tipo_struttura;

    do
    {
      struttura = scegliStrutturaHash();
      if (struttura == 0) { break; }

      tipo_struttura = scegliTipoStruttura();
      if (tipo_struttura == 0) { continue; }
        
      if (struttura == HTCLSADR ) // vogliamo testare un hashtable close addressing
      {
        if (tipo_struttura == INT)
        {
          lasd::HashTableClsAdr<int> hash_table;
          riempiHashTable(hash_table);
          testHashTable(hash_table);
        }
        else if (tipo_struttura == DOUBLE)
        {
          lasd::HashTableClsAdr<double> hash_table;
          riempiHashTable(hash_table);
          testHashTable(hash_table);
        }
        else if (tipo_struttura == STRING)
        {
          lasd::HashTableClsAdr<std::string> hash_table;
          riempiHashTable(hash_table);
          testHashTable(hash_table);
        }
      }
      else if (struttura == HTOPNADR) // vogliamo testare un hashtable open addressing
      {
        if (tipo_struttura == INT)
        {
          lasd::HashTableOpnAdr<int> hash_table;
          riempiHashTable(hash_table);
          testHashTable(hash_table);
        }
        else if (tipo_struttura == DOUBLE)
        {
          lasd::HashTableOpnAdr<double> hash_table;
          riempiHashTable(hash_table);
          testHashTable(hash_table);
        }
        else if (tipo_struttura == STRING)
        {
          lasd::HashTableOpnAdr<std::string> hash_table;
          riempiHashTable(hash_table);
          testHashTable(hash_table);
        }
      }
    } while (true);
  }

  ////////////////////////////////////////////////////////////////

  unsigned int scegliStrutturaHash()
  {
    unsigned int scelta;
    cout << "\nScegli quale struttura dati vuoi utilizzare:\n";
    cout << "1. Hash Table con CLOSED addressing\n";
    cout << "2. Hash Table con OPEN addressing\n";
    cout << "0. Esci\n\n";

    do
    {
      try
      {
        getValue(scelta);
        if (scelta == 0 || scelta == 1 || scelta == 2)
        {
          break;
        }
        else
        {
          throw invalid_argument("");
        }
      }
      catch (const logic_error &errore)
      {
        cout << "";
        //cout << "Errore: " << errore.what() << "\n";
      }
    } 
    while (true);

    return scelta;
  }

  ////////////////////////////////////////////////////////////////

  void riempiHashTable(lasd::HashTable<int> &hash_table)
  {
    for (unsigned long index = 0; index < DIMENSIONE_HT; index++)
    {
      hash_table.Insert(generaInt());
    }
  }

  void fillHashTable(lasd::HashTable<double> &hash_table)
  {
    for (unsigned long index = 0; index < DIMENSIONE_HT; index++)
    {
      hash_table.Insert(generaDouble());
    }
  }

  void fillHashTable(lasd::HashTable<std::string> &hash_table)
  {
    for (unsigned long index = 0; index < DIMENSIONE_HT; index++)
    {
      hash_table.Insert(generaString());
    }
  }

  ////////////////////////////////////////////////////////////////

  template <typename Data>
  void testHashTable(lasd::HashTable<Data>& ht)
  {
    unsigned int scelta;

    do
    {
      cout << "\n\n***** HashTable *****\n";
      cout << "\nScegli l'operazione da eseguire:\n";
      cout << "1. Visualizza HashMap generata\n";
      cout << "2. Clear\n";
      cout << "3. Exists di un valore\n";
      cout << "4. Test iteratori sull'albero\n";
      cout << "5. Insert valore\n";
      cout << "6. Remove valore\n";
      cout << "7. MinNRemove valore\n";
      cout << "8. MaxNRemove valore\n";
      cout << "9. Predecessor valore\n";
      cout << "10. PredecessorNRemove valore\n";
      cout << "11. Successor valore\n";
      cout << "12. SuccessorNRemove valore\n";
      cout << "0. Esci\n\n";

      try
      {
        getValue(scelta);

        if (scelta == 0)
        {
          break;
        }
        else if (scelta == 1)
        {
          cout << "\nLa size della hash table e': " << ht.Size() << "\n";
          cout << "\nLa table size della hash table e': " << ht.table_size << "\n";
          cout << "\n HashTable generata: \n";

          for (unsigned long index = 0; index < ht.table_size; ++index)
          {
            cout << "Bucket " << index << ": ";
            if (ht[index].)
            {
              std::cout << "Empty";
            }
            else
            {
              table_vector[index].InOrderTraversal([](const Data &data)
                                                   { std::cout << data << " "; });
            }
            std::cout << std::endl;
          }
        }
        else if (scelta == 2)
        {
          
        }
        else if (scelta == 3)
        {

        }
        else if (scelta == 4)
        {
         
        }
        else if (scelta == 5)
        {
          
        }
        else if (scelta == 6)
        {
         
        }
        else if (scelta == 7)
        {
         
        }
        else if (scelta == 8)
        {
         
        }
        else if (scelta == 9)
        {
       
        }
        else if (scelta == 10)
        {
         
        }
        else if (scelta == 11)
        {
         
        }
        else if (scelta == 12)
        {
          
        }
        else
        {
          throw invalid_argument("");
        }
      }
      catch (const std::length_error &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::out_of_range &errore)
      {
        cout << "\nErrore: " << errore.what() << "\n";
      }
      catch (const std::logic_error &errore)
      {
        cout << "\nErrore. Riprova!\n";
      }

    } 
    while (true);

  }


  





















  /* ************************************************************************** */
  /* ************************************************************************** */




