#define MAX_QUEUE_SIZE 10

class CircularQueue {

protected:
  int front; // 첫 번째 요소 앞의 위치
  int rear; // 마지막 요소 위치
  int data[MAX_QUEUE_SIZE]; // 요소의 배열
public:
  CircularQueue() { front = rear = 0; }
  bool isEmpty() { return front == rear; }
  bool isFull() { return (rear+1)%MAX_QUEUE_SIZE == front; }

  void enqueue(int val) { // 큐에 삽입
    if(isFull())
    error("error: 큐가 포화상태입니다\n");
    else {
      rear = (rear+1) % MAX_QUEUE_SIZE;
      data[rear] = val;
    }
  }

  int dequeue( ) { // 첫 항목을 큐에서 빼서 반환
    if(isEmpty()) error("Error: 큐가 공백상태입니다\n");
    else {
      front = (front+1) % MAX_QUEUE_SIZE;
      return data[front];
    }
  }

  int peek( ) { // 첫 항목을 큐에서 빼지 않고 반환
    if(isEmpty()) error("Error: 큐가 공백상태입니다\n");
    else
    return data[(front+1) % MAX_QUEUE_SIZE];
  }

  void display( ) { // 큐의 모든 내용을 순서대로 출력
    printf("큐 내용 : ");
    int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
    for( int i = front+1 ; i<=maxi ; i++ )
    printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
    printf("\n");
  }
}

class CircularDeque : public CircularQueue { // CircularQueue를 상속받은 CircularDeque
  public: // CircularQueue에서 이미 protected 타입으로 front, rear, 배열을 선언했기 때문에 자식 클래스는 그대로 사용 가능.
  CircularDeque() { }
  void addRear(int val) { enqueue(val);} // addRear는 부모 클래스의 enqueue()에 해당
  int deleteFront( ) { return dequeue(); } // deleteFront는 부모 클래스의 dequeue()에 해당
  int getFront( ) { return peek(); } // getFront는 부모 클래스의 peek()에 해당

  int addFront(int val){ // 덱의 맨 앞에 삽입
    if(isFull()){
      error("error\n");
    } else {
      data[front] = val;
      front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
  }

  int deleteRear(){
    if(isEmpty()) error("error");
    else{
      int ret = data[rear];
      rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
      return data[ret];
    }
  }

  void display( ) { // 덱의 모든 내용을 순서대로 출력
    printf( "덱 내용 : ");
    int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
    for( int i = front+1 ; i<=maxi ; i++ )
    printf( "[%2d] ", data[i%MAX_QUEUE_SIZE]);
    printf( "\n");
  }
}
