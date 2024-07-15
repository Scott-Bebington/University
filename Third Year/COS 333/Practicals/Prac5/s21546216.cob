       IDENTIFICATION DIVISION.
       PROGRAM-ID. Practical5.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 NumArr OCCURS 5 TIMES PIC 9(5).
       01 CountArr OCCURS 5 TIMES PIC 9(5).
       01 NumInd PIC 9(5) VALUE 1.
       01 NumInd2 PIC 9(5) VALUE 1.
       01 LargestNumber PIC 9(5) VALUE 1.
       01 SmallestNumber PIC 9(5) VALUE 1.
       01 ModalValue PIC 9(5) VALUE 1.
       01 ModalIndex PIC 9(5) VALUE 1.
       01 InputValue PIC 9(5) VALUE 1.
   
       PROCEDURE DIVISION.
           PERFORM readData
      *    PERFORM OUTPUT-ARRAY
           PERFORM findSmallest
           PERFORM findLargest
           PERFORM modal
           display "Smallest Number: " SmallestNumber
           display "Largest Number: " LargestNumber
           display "Modal Value: " ModalValue
           STOP RUN.
   
           readData.
           DISPLAY "Please enter 5 values, "
           "after each value click enter:"
           PERFORM VARYING NumInd FROM 1 BY 1 UNTIL NumInd > 5
               ACCEPT InputValue
               MOVE InputValue TO NumArr(NumInd)
           END-PERFORM.
           PERFORM RESET-OUTER-INDEX.

           OUTPUT-ARRAY.
           display "Array: " NumArr(1) ", " NumArr(2) ", " NumArr(3)  
           ", " NumArr(4) ", " NumArr(5).

           RESET-OUTER-INDEX.
           PERFORM MOVE 1 TO NumInd
           END-PERFORM.

           RESET-INNER-INDEX.
           PERFORM MOVE 1 TO NumInd2
           END-PERFORM.

           findSmallest.
           MOVE NumArr(1) TO SmallestNumber
           PERFORM VARYING NumInd FROM 1 BY 1 UNTIL NumInd > 5
             IF NumArr(NumInd) < SmallestNumber
                 MOVE NumArr(NumInd) TO SmallestNumber
                 END-IF
           END-PERFORM.
           PERFORM RESET-OUTER-INDEX.

           findLargest.
           MOVE NumArr(1) TO LargestNumber
           PERFORM VARYING NumInd FROM 1 BY 1 UNTIL NumInd > 5
             IF NumArr(NumInd) > LargestNumber
                 MOVE NumArr(NumInd) TO LargestNumber
                 END-IF
           END-PERFORM.
           PERFORM RESET-OUTER-INDEX.

           modal.
           MOVE 0 TO ModalValue
           PERFORM VARYING NumInd FROM 1 BY 1 UNTIL NumInd > 5
             PERFORM VARYING NumInd2 FROM 1 BY 1 UNTIL NumInd2 > 5
               IF NumArr(NumInd) = NumArr(NumInd2)
                 ADD 1 TO CountArr(NumInd2)
               END-IF
             END-PERFORM
             PERFORM RESET-INNER-INDEX
           END-PERFORM
           
           MOVE 0 TO NumInd
           MOVE -1 TO ModalValue
           MOVE -1 TO ModalIndex
           PERFORM VARYING NumInd FROM 5 BY -1 UNTIL NumInd = 0
              IF CountArr(NumInd) > ModalValue
               MOVE NumInd TO ModalIndex
              END-IF
           END-PERFORM
           MOVE NumArr(ModalIndex) TO ModalValue.
   
           
   
      * To compile the program, use the following command:
      * cobc -x s21546216.cob && ./s21546216
