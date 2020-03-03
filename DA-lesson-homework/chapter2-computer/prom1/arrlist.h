#ifndef _ARR_LIST_H_
#define _ARR_LIST_H_

struct ArrList;
typedef struct ArrList *List;

typedef int ElementType;
typedef ElementType *Position;

List initList(int capacity);
int length(List list);
int capacity(List list);
Position find(ElementType ele, List list);
void insert(ElementType ele, List list);
void deleteEle(ElementType ele, List list);
int isEmpty(List list);
void destroyList(List list);
void printList(List list);

List mergeList(List list1, List list2);

#endif /* _ARR_LIST_H */
