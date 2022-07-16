from conans import ConanFile


# -----------------------------------------------------------------------------
def configure(params={}):
    # example:
    # conanfile: ConanFile = params["conanfile"]
    # conanfile.options["openssl"].xyz = True
    pass


# -----------------------------------------------------------------------------
def requirements(params={}):
    conanfile: ConanFile = params["conanfile"]
    conanfile.requires("sqlite3/3.39.1")
    conanfile.requires("sqlitecpp/3.1.1")
