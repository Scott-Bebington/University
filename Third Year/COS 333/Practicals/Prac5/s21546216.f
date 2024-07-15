      program main
      integer :: arr(5)
      integer :: smallest, largest, mode
    
      call readData(arr)
      smallest = findSmallest(arr)
      largest = findLargest(arr)
      mode = findMode(arr)
    
      ! Print the results
      print *, "Smallest value:", smallest
      print *, "Largest value:", largest
      print *, "Mode value:", mode
    
      contains
    
      subroutine readData(arr)
        integer, intent(out) :: arr(5)
        integer :: i
        
        print *, "Enter 5 integers:"
        do i = 1, 5
            read(*, *) arr(i)
        end do
        
      end subroutine readData
    
      function findSmallest(arr) result(smallest)
        integer, intent(in) :: arr(5)
        integer :: i, smallest
        
        smallest = arr(1)
        do i = 2, 5
            if (arr(i) < smallest) then
                smallest = arr(i)
            end if
        end do
        
      end function findSmallest
    
      function findLargest(arr) result(largest)
        integer, intent(in) :: arr(5)
        integer :: i, largest
        
        largest = arr(1)
        do i = 2, 5
            if (arr(i) > largest) then
                largest = arr(i)
            end if
        end do
        
      end function findLargest
    
      function findMode(arr) result(mode)
        integer, intent(in) :: arr(5)
        integer :: i, j, mode, count, maxCount
        
        maxCount = 0
        do i = 1, 5
            count = 0
            do j = 1, 5
                if (arr(j) == arr(i)) then
                    count = count + 1
                end if
            end do
            
            if (count > maxCount) then
                maxCount = count
                mode = arr(i)
            end if
        end do
        
      end function findMode
    
      end program main


! To run:
! gfortran -o outputfile s21546216.f && ./outputfile