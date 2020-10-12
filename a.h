int main() {
//    int arr[3] = {1, 4, 7};
//    ArraySequence <int> abc (arr, 3);
//    ArraySequence <int> abc2 = abc.getSubSeq(1, 2);
//    for (int i = 1; i < 4; ++i) {
//        abc[i - 1] = i*i;
//    }
//    abc2.print();
//    cout << "\n" << endl;
//
//    ArraySequence <int> abc3 = abc.concat(abc, abc2);
//    abc3.print();
//    cout << "\n" << endl;



//    cout << "\nList\n" << endl;
//
//    int arr2[4] = {1, 7, 8, 15};
//    LinkedListSequence<int> a(arr2, 4);
//    LinkedListSequence<int> b = a;
//    a[0] = 5;
//    a[1] = 8;
//    a.print();
//    cout << "\n" << endl;
//
//    b.print();
//    cout << "\n" << endl;
//
//    LinkedListSequence<int> c = a.concat(a, b);
//    cout << "\nc\n" << endl;
//    c.print();
//
//    LinkedListSequence<int> d = c.getSubSeq(2, 3);
//    cout << "\nd\n" << endl;
//    d.print();


//    QueueSequence<int> a;
//    a.addNode(1);
//    a.addNode(3);
//    a.addNode(7);
//
//    a.print();
//    cout << "\n" << endl;
//
//    QueueSequence <int> b = a.GetSubList(1, 2);
//    b.print();
//    cout << "\n" << endl;
//
//    QueueSequence <int> c = a.concat(a, b);
//    c.print();
//    cout << "\n" << endl;
//
//    QueueSequence <int> d = a.map(kvI);
//    d.print();
//    cout << "\n" << endl;
//
//    QueueSequence <bool> bl = a.where(whI);
//    bl.print();
//    cout << "\n" << endl;
//
//    int r = a.reduce(rdI, 100);
//    cout << "reduce = " << r << endl;

//    QueueSequence<complex> a;
//    complex num{};
//    num.real = 1;
//    num.imagine = -3;
//    complex num2{};
//    num2.real = 3;
//    num2.imagine = 10;
//    a.addNode(num);
//    a.addNode(num2);
//    a.addNode(num);
//
//    a.printComplex();
//    cout << "\n" << endl;
//
//    QueueSequence <complex> b = a.GetSubList(1, 2);
//    b.printComplex();
//    cout << "\n" << endl;
//
//    QueueSequence <complex> c = a.concat(a, b);
//    c.printComplex();
//    cout << "\n" << endl;
//
//    QueueSequence <complex> d = a.map(kvC);
//    d.printComplex();
//    cout << "\n" << endl;
//
//    QueueSequence <bool> bl = a.where(whC);
//    bl.print();
//    cout << "\n" << endl;
//
//    complex r = a.reduce(rdC, num);
//    cout << "reduce = " << r.real << endl;

    return 0;
}