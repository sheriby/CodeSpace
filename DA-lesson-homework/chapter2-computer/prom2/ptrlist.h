#ifndef _PTR_LIST_H_
#define _PTR_LIST_H_

struct ListNode;
typedef struct ListNode *List;

typedef int ElementType;
typedef List Position;

List initlist();
int size(List list);
Position find(ElementType ele, List list);
void insert(ElementType ele, List list);
void deleteEle(ElementType ele, List list);
void deletePos(Position pos, List list);
int isEmpty(List list);
void destroyList(List list);
void printList(List list);

List mergeList(List list1, List list2);
void copyList(List src, List dst);

#endif /* _PTR_LIST_H_ */
