class Employee
    attr_reader :earnings

    def initialize(baseSalary = 20000.00)
        @earnings = 0.0
        @baseSalary = baseSalary
        @baseSalaryPaid = false
    end

    def payEmployee
        unless @baseSalaryPaid
            @earnings += @baseSalary
            @baseSalaryPaid = true
        end
    end

    def newMonth
        @baseSalaryPaid = false
    end
end

class Manager < Employee
    def initialize(baseSalary = 20000.00, bonus)
        super(baseSalary)
        @bonus = bonus
    end

    def payEmployee
        super
        @earnings += @bonus
    end
end

class Programmer < Employee
    def initialize(percentage)
        computed_salary = 20000.00 * percentage
        super(computed_salary)
    end
end

class Team
    def initialize(manager)
        @employees = []
        @manager = manager

    end

    def addMember(employee)
        if @employees.length >= 2
            raise "Maximum number of employees reached"
        end
        @employees << employee
    end

    def payTeam
        @employees.each do |employee|
            employee.payEmployee
        end
        @manager.payEmployee
    end

    def newMonth
        @employees.each do |employee|
            employee.newMonth
        end
    end

    def printEarnings
        puts "Earnings for Manager: #{@manager.earnings}"
        @employees.each do |employee|
            puts "Earnings for #{employee.class}: #{employee.earnings}"
        end
    end
end



puts "Enter details for the manager:"
print "Base Salary: "
base_salary = gets.chomp.to_f
print "Bonus: "
bonus = gets.chomp.to_f

if base_salary.zero?
    base_salary = 20000.00
end

manager = Manager.new(base_salary, bonus)

team1 = Team.new(manager)
team2 = Team.new(manager)

# team1.addMember(manager)
# team2.addMember(manager)

puts "Enter details for the programmer in team 1:"
print "Percentage: "
percentage = gets.chomp.to_f

programmer1 = Programmer.new(percentage)
team1.addMember(programmer1)

puts "Enter details for the programmer in team 2:"
print "Percentage: "
percentage = gets.chomp.to_f

programmer2 = Programmer.new(percentage)
team2.addMember(programmer2)

pay_another_month = true

while pay_another_month
    puts "Do you want to pay the teams for another month? (y/n)"
    choice = gets.chomp.downcase

    case choice
    when "y"
        team1.payTeam
        team2.payTeam
        team1.newMonth
        team2.newMonth
    when "n"
        pay_another_month = false
    else
        puts "Invalid choice. Please enter 'y' or 'n'."
    end
end
print "Team 1: "
team1.printEarnings
print "Team 2: "
team2.printEarnings