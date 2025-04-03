;; Summer Olmstead Assignment 12 
;; 1. Prime Number Generator used https://www.jdoodle.com/execute-scheme-online
;; Description: Implement a prime number generator that returns all prime numbers up to a specified limit using a recursive approach.
;; The lists are used to store primes.
;; Optimize the solution and handle larger limits using the Sieve of Eratosthenes.
;;ugh for some reason the comment placement changes the outcome of if the code can run or not 

;;first we are going to recursively implement the Sieve of Eratosthenes to filter out non-primes
(define (sieve lst)
  (if (null? lst) ;; if nothing then return empty list 
      '()
      (cons (car lst)
            (sieve ;;check through our sieve to see if its prime
             (filter (lambda (x)  ;;filter only if prime and check every vaue in list
                       (let ((current-prime (car lst)) ;; checks based from current prime
                             (remainder (modulo x (car lst)))) ;; checks remainder 
                         (not (zero? remainder)))) ;;cant have divisable remainder
                     (cdr lst))))))

;;a range function with parameters start and end generate a list of numbers
(define (range start end)
  (if (> start end)
      '()
      (cons start
            (range (+ start 1) end))))

;;the limit function for prime number generation gonna use by user 
(define (prime-generator limit)
  (if (< limit 2)
      '() ;; no primes less than 2 bc then no list
      (let ((full-list (range 2 limit)))  ;;generate the list from 2 to limit
        (sieve full-list))))  ;;apply the sieve to filter out non-primes in our limit list range 

;;main program define
(define (main)
  (begin
    ;;intro message! 
    (display "Welcome to the prime number generator!\n")
    (display "It will generate all prime numbers up to a given limit which you can input!\n")
    (display "For example, if we input 50, it will return all prime numbers up to 50 :D !\n")
    (newline)
    
    ;;user for input limit
    (display "Please enter the limit up to which you want to generate prime numbers: :)\n")
    
    ;;let to bind the user input instead of define bc didnt work other way 
    (let ((user-limit (read)))  ;;read the user input for the limit
      (if (not (number? user-limit)) ;; check if the input is a number
          (begin
            (display "Invalid input. Please enter a valid number.\n"))
          (begin
            ;;generate primes up to the input limit
            (display (string-append "Generating primes up to " (number->string user-limit) "...\n"))
            
            ;;user-specified limit picks generation amount for list
            (let ((primes (prime-generator user-limit))) 
              (display "The prime numbers are: ")
              (display primes)
              (newline)))))))

;;main
(main) ;; Calling main with no arguments

