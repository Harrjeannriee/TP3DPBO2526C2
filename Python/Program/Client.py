# Client
class Client:
    def __init__(self, Id, Name, Email):
        self.Id = Id
        self.Name = Name
        self.Email = Email
        self.Commission = None

    # Getter for class Client
    def getId(self):
        return self.Id
    def getName(self):
        return self.Name
    def getEmail(self):
        return self.Email

    # Setter for class Client
    def setId(self, Id):
        self.Id = Id
    def setName(self, Name):
        self.Name = Name
    def setEmail(self, Email):
        self.Email = Email


    # Composition
    def addCommission(self, Commission):
        self.Commission = Commission