#ifndef ARRAYLIST_H
#define ARRAYLIST_H

  class ArrayList {
		
	  public:
			ArrayList();
			ArrayList(int);
			bool insertElement(int);
			void sort();
			bool isFull();
			bool isEmpty();
			void print();
			virtual ~ArrayList();
		protected:
			virtual bool directionOperator(int,int) = 0;
		private:
			int size;
			int current;
			int* storage;
	};


  class AscendingArrayList : public ArrayList {
		public:
			AscendingArrayList();
			AscendingArrayList(int);
		protected:
			virtual bool directionOperator(int,int);
		
	};

	class DescendingArrayList : public ArrayList {
		public:
			DescendingArrayList();
			DescendingArrayList(int);
		protected:
			virtual bool directionOperator(int,int);
	};

#endif
