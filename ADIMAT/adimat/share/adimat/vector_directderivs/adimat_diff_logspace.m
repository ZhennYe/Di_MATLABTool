function varargout = adimat_diff_logspace(varargin)

        r = logspace(varargin{2}, varargin{4}, varargin{5});
        varargout{2} = r;
        lp01 = log(10) .* linspace(0, 1, varargin{5});
        % varargin{1} and varargin{3} are derivatives of scalars!
        varargout{1} = varargin{3} * (r .* lp01) + varargin{1} * (r .* fliplr(lp01));
        varargout{1} = reshape(varargout{1}, [size(varargout{1}, 1) size(varargout{2})]);

      
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
