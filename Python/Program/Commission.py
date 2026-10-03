# Class Comission 
class Commission:
    def __init__(self, IdReq, Request, Deadline):
        self.IdReq = IdReq
        self.Request = Request
        self.Deadline = Deadline
        self.Artwork = None

    # Getter for class Commission
    def getIdreq(self):
        return self.IdReq
    def getRequest(self):
        return self.Request
    def getDeadline(self):
        return self.Deadline

    # Setter for class Commission
    def setIdReq(self, IdReq):
        self.IdReq = IdReq
    def setRequest(self, Request):
        self.Request = Request
    def setDeadline(self, Deadline):
        self.Deadline = Deadline

    # Composition
    def addArtwork(self, Artwork):
        self.Artwork = Artwork