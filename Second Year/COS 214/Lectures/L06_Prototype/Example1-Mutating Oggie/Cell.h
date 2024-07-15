#ifndef CELL_H
#define CELL_H

  class Cell {
		public:
			Cell();
			virtual Cell* divide() = 0;
			void print();
			virtual ~Cell();
		protected:
			Cell(const Cell&);
			char* str;
	};

	class NormalCell : public Cell {
		public:
			NormalCell();
			virtual Cell* divide();
    protected:
      NormalCell(const NormalCell&);
	};

	class AbnormalCell : public Cell {
		public:
			AbnormalCell();
			virtual Cell* divide();
    protected:
      AbnormalCell(const AbnormalCell&);

	};
#endif

