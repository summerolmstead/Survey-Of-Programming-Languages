;;simple chatbot Summer Olmstead Assignment 12
;;Description: Create a basic chatbot that can hold simple conversations. The bot should use pattern matching to recognize keywords or phrases and respond accordingly. It uses:
;;Recursion (for continuing the conversation)
;;Lists (for predefined responses)
;;Conditionals (for recognizing user input)

;;keyword-response pairs for convo automated responses 
(define responses
  '((("hello" "hi" "hey") "Hello! How can I help you? :) ")
    (("bye" "goodbye") "Goodbye! Have a great day! ;) ")
    (("what's up" "sup" "how's it going") "Not much, just here to chat with you! hehe")
    (("how are you") "I'm just a program, but I'm doing fine today - as good as I can be -_- !")
    (("help") "Sure, I can help! What do you need?")
    (("what" "favorite animal") "My favorite animal is a Dolphin! :D What is yours?")
    (("dog" "cat" "dolphin" "elephant" "monkey" "bird" "lizard" "giraffe") "Wow, that is a cool one! I do like all animals :) ")
    (("what" "favorite color") "My favorite color? Wow, I am happy you asked! It is pink today -_- ")
    (("pink" "blue" "black" "yellow" "orange" "purple" "green") "Wow I love that one!!! Very pretty.")
    (("what" "favorite food") "I do not really eat food, but I like being charged hahahahah.... what is yours?")
    (("my food is") "Wow that does sound pretty tasty... Maybe I can try it one day!")
    (("2+2" "math" "add") "Hmm 2 plus 2 is 4! At least I think hehehe ")
    (("who are you" "what are you") "I am a friendly chatbot here to speak with you! :D ")
    (("sad" "upset" "unhappy") " I'm sorry to hear that. I'm here for you! I can tell you a joke if you want... ")
    (("joke") "Why did the chicken cross the road? ............... Because it was free range! XD ")
    (("funny") "Why don't programmers like nature?...... Too many bugs.!!!! XD ")
    (("happy" "excited") "That's awesome! I'm glad you're feeling good! :3 ")
    (("time" "clock") "I don't have a watch, but it's always a good time to learn! ;)")
    (("where" "you live") "I live in the cloud :O floating through code...... :p ")
    (("good morning" "morning") "Good morning! Hope your day starts off great :D !")
    (("good night" "night") "Good night! Sleep well. Do not let the DEBUGs bite!!!")
    (("ai" "robot") "Yea I am planning to take over the WORLD!!!! Haha, I am kidding. I'm a bot powered by simple code. But I like learning!")
    (("what" "favorite movie") "I really like sci-fi movies like Terminator ;) ")
    (("real") "As real as code can be! :D ")
    (("have" "feelings" "feel") "Hmm... no I do not have feelings but I just do my thing XD ")
    (("sing") "La la la ! Just a chatbot trying my best! @-@ ")
    (("tired") "Rest is important! Don’t forget to take breaks O-o ")
    (("thank" "thanks") "You're welcome! :D ")
    (("default") "I'm not sure I understand. Can you rephrase?")))


;;convert input to string so its easier to read if theres ! or ? from user etc 
(define (normalize input)
  (cond
    ((symbol? input) (symbol->string input))
    ((string? input) input)
    (else "")))

;;if keyword is in input string (simple version of string-contains)
(define (my-string-contains? str keyword)
  (let loop ((i 0))
    (cond
      ((> i (- (string-length str) (string-length keyword))) #f) ;;false if the keyword isnt there
      ((string=? (substring str i (+ i (string-length keyword))) keyword) #t) ;;return true if it is
      (else (loop (+ i 1)))))) ;; keeps looping through until keyword is found

;;check if any keyword matches in input
(define (contains-keyword? input keywords)
  (cond
    ((null? keywords) #f) ;; in case keywords are empty then false
    ((my-string-contains? input (car keywords)) #t) ;;if keyword is first in list then return true
    (else (contains-keyword? input (cdr keywords))))) ;; if not first then recursively check the rest 

;;find the appropriate response after keyword found - using list function to grab 1st and second elms
(define (match-input input patterns)
  (cond
    ((null? patterns) "I'm not sure I understand. Can you rephrase?") ;;default response if no match found
    ((contains-keyword? input (car (car patterns))) (cadr (car patterns))) ;;if the keyword is in the first pattern to match input then use this
    (else (match-input input (cdr patterns))))) ;;else check other patterns 

;;chatbot function to keep asking for input until bye or goodbye
(define (chatbot)
  (display "You: ") ;; user line talking
  (let* ((raw-input (read-line))  ;;get the new user input
         (user-input (normalize raw-input)))  ;;normalize input (to string) func we did
    (let ((response (match-input user-input responses))) ;; get response
      (display " Chatty Bot: ") ;; bot begins talking
      (display response)
      (newline)
      ;;if the user says "bye" or "goodbye" we are gonna end the conversation
      (if (not (or (equal? user-input "bye") (equal? user-input "goodbye")))
          (chatbot)))))  ;;continue listening for the next input

;;start the bot to talk based on user input :)
(chatbot)