from robot_control_class import RobotControl

# DEFINING ROBOT MOTION CLASS for RobotNik Summit
class summitbotcontrol():
    def __init__(self, motion, direction, speed, time):
        self.summitbot = RobotControl(robot_name="summit")
        self.motion = motion
        self.direction = direction
        self.speed = speed
        self.time = time
        self.turnspeed = 1.15
        self.turntime = 1.98

    def startpoint(self):
        self.summitbot.move_straight_time('forward', 1, 6)
        self.summitbot.turn('clockwise', 1.15, 1.98)

    def square_motion(self):
        i = 0
        while i < 4:
            self.move_straight()
            self.turn_move()
            i += 1

        self.stop_bot()

    def move_straight(self):
        self.summitbot.move_straight_time(self.motion, self.speed, self.time)

    def turn_move(self):
        self.summitbot.turn(self.direction, self.turnspeed, self.turntime)

    def stop_bot(self):
        self.summitbot.stop_robot()

# END OF CLASS DEFINITION ---------------------------------------------------

# MOTION CLASS INSTANCES
duration = 3
rm1 = summitbotcontrol('forward', 'clockwise', 1, duration)
rm1.startpoint()
rm1.square_motion()
rm2 = summitbotcontrol('forward', 'clockwise', 1, float(duration/2))
rm2.square_motion()